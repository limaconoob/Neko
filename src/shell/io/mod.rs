use ::chan;
use ::pty::prelude as pty;

use std::io::{Read, Write};
use std::io;
use std::thread;

pub type Out = ([u8; 4096], usize);
pub type In = ([u8; 1], usize);


pub struct Io {
  master: pty::Master,
  rx_in: chan::Receiver<In>,
  rx_out: chan::Receiver<Out>,
}

impl Io {
  fn new (
    master: pty::Master,
    rx_in: chan::Receiver<In>,
    rx_out: chan::Receiver<Out>,
  ) -> Self {
    ::terminal::setup_terminal(master);
    Io {
      master: master,
      rx_in: rx_in,
      rx_out: rx_out,
    }
  }

  pub fn from_master(mut master: pty::Master) -> Self {
    let (tx_out, rx_out) = chan::sync(0);

    thread::spawn(move || {
      let mut bytes = [0u8; 4096];
      loop {
        let read = master.read(&mut bytes).unwrap();

        tx_out.send((bytes, read));
      }
    });
    let (tx_in, rx_in) = chan::sync(0);

    thread::spawn(move || {
      let mut bytes = [0u8; 1];
      loop {
        let read = io::stdin().read(&mut bytes).unwrap();

        tx_in.send((bytes, read));
      }
    });
    Io::new(master, rx_in, rx_out)
  }
}

impl Iterator for Io {
  type Item = (Option<u8>, Option<Out>);

  fn next(&mut self) -> Option<(Option<u8>, Option<Out>)> {
    let ref recv_rx_in: chan::Receiver<([u8; 1], usize)> = self.rx_in;
    let ref recv_rx_out: chan::Receiver<([u8; 4096], usize)> = self.rx_out;
    let (mut rx_in, mut rx_out): (Option<In>, Option<Out>) = (None, None);

    chan_select! {
      recv_rx_out.recv() -> val => {
        if let Some((bytes, nread)) = val {
          if nread.checked_neg().is_none() {
            rx_out = Some((bytes, nread));
            ::std::io::stdout().write(&bytes[..nread]).unwrap();
            ::std::io::stdout().flush().unwrap();
          }
        }
      },
      recv_rx_in.recv() -> val => {
        if let Some((bytes, nread)) = val {
          rx_in = Some((bytes, nread));

          self.master.write(&bytes[..nread]).unwrap();
          self.master.flush().unwrap();
        }
      },
    };
    match (rx_in, rx_out) {
      (None, None) => None,
      (None, r_out) => Some((None, r_out)),
      (Some((key, 1)), r_out) => Some((Some(key[0]), r_out)),
      _ => None,
    }
  }
}
