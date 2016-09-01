mod err;
mod io;
pub mod event;

use ::std::collections::VecDeque;
use ::std::fmt;

use ::pty::prelude as pty;
use ::fork::Child;

use self::io::Io;
use self::event::Event;
pub use self::err::{ShellError, Result};

pub struct Shell {
  io: Io,
  pty: pty::Fork,
  output: VecDeque<u8>,
  input: VecDeque<Vec<u8>>,
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
            output: VecDeque::with_capacity(4096),
            input: {
              let mut input = VecDeque::with_capacity(1024);

              input.push_back(Vec::with_capacity(1024));
              input
            },
          })
        },
      },
    }
  }
}

impl Iterator for Shell {
  type Item = Option<Event>;

  fn next(&mut self) -> Option<Option<Event>> {
    match self.io.next() {
      None => None,
      Some((rx_in, rx_out)) => {
        if let Some((rx_out_buf, rx_out_len)) = rx_out {
            if self.output.len() + rx_out_len >= self.output.capacity() {
              for _ in 0..rx_out_len {
                self.output.pop_front().unwrap();
              }
            }
            self.output.extend(rx_out_buf[..rx_out_len].iter());
        };
        match rx_in {
          None => Some(None),
          Some(r_in) => {
            let mut line: Vec<u8> = Vec::with_capacity(1024);

            if let Some(ref mut last) = self.input.iter_mut().last() {
              last.push(r_in);
              line.extend_from_slice(&last[..]);
            }
            if r_in != 10 && r_in != 13 {
              Some(Some(Event::KeyDown(r_in)))
            }
            else {
              self.input.push_back(Vec::with_capacity(1024));
              Some(Some(Event::Command(line)))
            }
          },
        }
      },
    }
  }
}

impl fmt::Display for Shell {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "{}", String::from_utf8(Vec::from(self.output.clone())).unwrap())
  }
}
