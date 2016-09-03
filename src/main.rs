extern crate neko;

use neko::prelude as shell;

use std::io::Write;

fn main() {
  let mut shell: shell::Shell = shell::Shell::new(None).unwrap();

  while let Some(input) = shell.next() {
    if let Some(event) = input {
      match event {
        shell::Event::KeyDownEnterCommand(line) => {
          shell.write(&[10u8]);
          shell.flush();
        },
        shell::Event::KeyDown(key) => {
          shell.write(&[key]);
          shell.flush();
        },
      }
    }
  }
  println!("end");
}
