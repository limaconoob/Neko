extern crate neko;

use neko::prelude as shell;

use std::io::Write;

fn main() {
  let mut shell: shell::Shell = shell::Shell::new(None).unwrap();

  while let Some(shell::State(command, key)) = shell.next() {
    if let Some(_) = command {
      shell.write(&[10u8]).unwrap();
      shell.flush().unwrap();
    }
    if let Some(k) = key {
      shell.write(&[k]).unwrap();
      shell.flush().unwrap();
    }
  }
  println!("bye bye");
}
