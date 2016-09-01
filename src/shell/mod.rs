mod io;
mod err;

use std::collections::VecDeque;

use ::pty::prelude as pty;
use ::fork::Child;

use self::io::Io;
pub use self::err::{ShellError, Result};

pub struct Shell {
  io: Io,
  pty: pty::Fork,
  historic: VecDeque<Vec<u8>>,
}

impl Shell {
  pub fn new (
    command: Option<&'static str>,
  ) -> Result<Self> {
    match pty::Fork::from_ptmx() {
      Err(cause) => Err(ShellError::BadFork(cause)),
      Ok(fork) => match fork {
        pty::Fork::Child(ref slave) => {
          slave.exec(command.unwrap_or("bash"));
        },
        pty::Fork::Father(_, master) => {
          Ok(Shell {
            io: Io::from_master(master),
            pty: fork,
            historic: VecDeque::with_capacity(1024),
          })
        },
      },
    }
  }
}

impl Iterator for Shell {
  type Item = u8;

  fn next(&mut self) -> Option<u8> {
    match self.io.next() {
      None => None,
      Some(((in_buf, in_len), (out_buf, out_len))) => {
        if self.historic.len() >= self.historic.capacity() {
          self.historic.pop_front().unwrap();
        }
        self.historic.push_back(in_buf[..in_len].to_vec());
//        io::stdout().write(&x[..u]).unwrap();
        Some(out_buf[out_len])
      },
    }
  }
}
