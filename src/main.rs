extern crate neko;

use neko::prelude as shell;

fn main() {
  let mut shell: shell::Shell = shell::Shell::new(None).unwrap();

  while let Some(input) = shell.next() {
    if let Some(event) = input {
      match event {
        shell::Event::Command(line) => {
          println!("command: {}", String::from_utf8(line).unwrap());
        },
        shell::Event::KeyDown(key) => {
          if key == 27 { // Esc
            println!("{}", shell);
          }
          else {
            println!("{}", key);
          }
        },
      }
    }
  }
  println!("end");
}
