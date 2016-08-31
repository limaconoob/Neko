mod receiver;
mod err;

use ::pty::prelude as pty;
use ::fork::Child;

use self::receiver::Receiver;
pub use self::err::{ShellError, Result};

struct Shell {
  io: Receiver,
  pty: pty::Fork,
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
        pty::Fork::Father(_, mut master) => {
          Ok(Shell {
            io: Receiver::from_master(master),
            pty: fork,
          })
        },
      },
    }
  }
}
