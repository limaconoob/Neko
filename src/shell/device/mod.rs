use ::chan;
use ::pty::prelude as pty;

use std::io::{Read, Write};
use std::io;
use std::thread;

pub type In = ([u8; 1], usize);
pub type Out = ([u8; 4096], usize);

/// The struct `Device` is the input/output terminal interface.

pub struct Device {
  speudo: pty::Master,
  input: chan::Receiver<In>,
  output: chan::Receiver<Out>,
}

impl Device {
  fn new (
    speudo: pty::Master,
    input: chan::Receiver<In>,
    output: chan::Receiver<Out>,
  ) -> Self {
    ::terminal::setup_terminal(speudo);
    Device {
      speudo: speudo,
      input: input,
      output: output,
    }
  }

  pub fn from_speudo(mut master: pty::Master) -> Self {
    let (tx_out, rx_out) = chan::sync(0);
    let (tx_in, rx_in) = chan::sync(0);

    thread::spawn(move || {
      let mut bytes = [0u8; 4096];

      while let Some(read) = master.read(&mut bytes).ok() {
        tx_out.send((bytes, read));
      }
    });
    thread::spawn(move || {
      let mut bytes = [0u8; 1];

      while let Some(read) = io::stdin().read(&mut bytes).ok() {
        tx_in.send((bytes, read));
      }
    });
    Device::new(master, rx_in, rx_out)
  }
}

impl io::Write for Device {
  fn write(&mut self, buf: &[u8]) -> io::Result<usize> {
    self.speudo.write(buf)
  }

  fn flush(&mut self) -> io::Result<()> {
    self.speudo.flush()
  }
}

impl Iterator for Device {
  type Item = (Option<u8>, Option<Out>);

  fn next(&mut self) -> Option<(Option<u8>, Option<Out>)> {
    let ref input: chan::Receiver<([u8; 1], usize)> = self.input;
    let ref output: chan::Receiver<([u8; 4096], usize)> = self.output;
    let (mut rx_in, mut rx_out): (Option<In>, Option<Out>) = (None, None);

    chan_select! {
      output.recv() -> val => {
        if let Some((buf, len)) = val {
          if len.checked_neg().is_none() {
            rx_out = Some((buf, len));
          }
        }
      },
      input.recv() -> val => {
        if let Some(read) = val {
          rx_in = Some(read);
        }
      },
    };
    match (rx_in, rx_out) {
      (None, None) => None,
      (None, out) => Some((None, out)),
      (Some((key, 1)), r_out) => Some((Some(key[0]), r_out)),
      _ => None,
    }
  }
}
