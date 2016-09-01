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
  type Item = (In, Out);

  fn next(&mut self) -> Option<(In, Out)> {
    match self.rx_in.iter().zip(&self.rx_out)
                           .next() {
      None => unimplemented!(),
      Some(((_, in_len), _)) if in_len == 0 => None,
      io => {
        if let Some(((in_buf, in_len), (out_buf, out_len))) = io {
          self.master.write(&out_buf[..out_len]).unwrap();
          io
        }
        else {
          unimplemented!()
        }
      },
    }
  }
}
