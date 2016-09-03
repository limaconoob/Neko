mod err;
mod log;
mod device;
pub mod state;
pub mod command;

use ::std::collections::VecDeque;
use ::std::fmt;
use ::std::io;
use ::std::io::{Read, Write};

use ::pty::prelude as pty;
use ::fork::Child;
use ::libc;

use self::device::Device;
use self::state::State;
use self::command::Command;
use self::log::Log;
pub use self::err::{ShellError, Result};

/// The struct `Shell` is the speudo terminal interface.

pub struct Shell {
  pid: libc::pid_t,
  pty: pty::Fork,
  device: Device,
  log: Log,
  line: Command,
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
        pty::Fork::Father(pid, master) => {
          Ok(Shell {
            pid: pid,
            pty: fork,
            device: Device::from_speudo(master),
            log: Log::default(),
            line: Vec::with_capacity(4096),
          })
        },
      },
    }
  }
}

impl Iterator for Shell {
  type Item = State;

  fn next(&mut self) -> Option<State> {
    match self.device.next() {
      None => None,
      Some((rx_in, rx_out)) => {
        if let Some((rx_out_buf, rx_out_len)) = rx_out {
          self.log.extend(Vec::from(&rx_out_buf[..rx_out_len]));
          io::stdout().write(&rx_out_buf[..rx_out_len]).unwrap();
          io::stdout().flush().unwrap();
        };
        match rx_in {
          None => Some(State::default()),
          Some(10) | Some(13) => {
            let ll = self.line.clone();

            self.line.clear();
            Some(State(Some(ll), Some(10)))
          },
          Some(key) => {
            self.line.push(key);
            Some(State(None, Some(key)))
          },
        }
      },
    }
  }
}

impl io::Write for Shell {
  fn write(&mut self, buf: &[u8]) -> io::Result<usize> {
    self.device.write(buf)
  }

  fn flush(&mut self) -> io::Result<()> {
    self.device.flush()
  }
}
