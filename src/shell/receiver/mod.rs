use ::chan;
use ::pty::prelude as pty;
use ::fork::Father;

use std::io::{Read, Write};
use std::io;
use std::thread;

pub type Out = ([u8; 4096], usize);
pub type In = ([u8; 1], usize);

pub struct Receiver {
  master: pty::Master,
  rx_in: chan::Receiver<In>,
  rx_out: chan::Receiver<Out>,
}

impl Receiver {
  fn new (
    master: pty::Master,
    rx_in: chan::Receiver<In>,
    rx_out: chan::Receiver<Out>,
  ) -> Receiver {
    Receiver {
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
    Receiver::new(master, rx_in, rx_out)
  }
}

pub type Event = (Option<In>, Option<Out>);

impl Iterator for Receiver {
  type Item = Event;

  fn next(&mut self) -> Option<Event> {
    self.rx_in.iter().zip(&self.rx_out)
                     .map(|((in_buf, in_len), (out_buf, out_len))| {
      io::stdout().write(&in_buf[..in_len]).unwrap();
      io::stdout().flush().unwrap();

      self.master.write(&out_buf[..out_len]).unwrap();
      self.master.flush().unwrap();
    });
    None
  }
}
