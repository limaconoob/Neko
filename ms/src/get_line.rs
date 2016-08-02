///bonjour

use std::io::{stdout, stdin};
use std::io::prelude::*;
use event::Key;
use input::TermRead;
use raw::IntoRawMode;
use parse::ft_concat;
use parse::split_spaces;
use std::fmt;

impl fmt::Display for Key
{ fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result 
  { write!(f, "{}", self) }}

///command_line
pub fn command_line() -> Vec<String>
{ let stdout = stdout();
  let mut stdout = stdout.lock().into_raw_mode().unwrap();
  let stdin = stdin();
  print!("jpepin $> ");
  stdout.flush().unwrap();
  let mut buf: Vec<Key> = Vec::new();
  for c in stdin.lock().keys()
  { let b = c.unwrap();
    buf.push(b);
    match b
    { Key::Char('\n') => break,
      Key::Char('\0') => break,
      Key::Char(b) => print!("{}", b),
      Key::Alt(b) => print!("^{}", b),
      Key::Ctrl(b) => print!("*{}", b),
    //  Key::Left => move_it(LIN),
    //  Key::Right => move_it(REC),
    //  Key::Up => get_history(TOP),
    //  Key::Down => get_history(UNT),
    //  Key::Backspace => del_char(),
      _ => {}, };
    stdout.flush().unwrap(); }
  split_spaces(ft_concat(buf)) }
