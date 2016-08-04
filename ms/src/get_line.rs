///bonjour

use std::io::{stdout, stdin, self};
use std::io::prelude::*;
use event::Key;
use cursor::Left;
use cursor::Right;
use cursor::Up;
use input::TermRead;
use raw::IntoRawMode;
use parse::ft_concat;
use parse::split_spaces;
use std::fmt;

/*  let mut buf = [0; 9]; 
  buf = f.take(9);
  let mut coucou: Vec<char> = Vec::with_capacity(9); 
  for i in buf.iter()
  { coucou.push(i as char); }
  coucou }
*/
impl fmt::Display for Key
{ fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result 
  { write!(f, "{}", self) }}

//  let term: Term = Term{line: String::new(), curs_x: 11, curs_y: cursor_position()};
//  println!("{}, {}", term.curs_x, term.curs_y);

trait Bonjour
{ fn curs_pos(&mut self) -> io::Result<Option<String>>;
  fn read_pass<W: Write>(&mut self, writer: &mut W) -> io::Result<Option<String>>
   { let _raw = try!(writer.into_raw_mode());
     self.curs_pos() }}

impl<R: Read> Bonjour for R
{ fn curs_pos(&mut self) -> io::Result<Option<String>>
  { let mut buf = Vec::with_capacity(30);
    for c in self.bytes()
    { match c
      { Err(e) => return Err(e),
        Ok(b'R') => break,
        Ok(c) => buf.push(c), }}
  let string = try!(String::from_utf8(buf).map_err(|e| io::Error::new(io::ErrorKind::InvalidData, e)));
  Ok(Some(string)) }}

pub fn cursor_position() -> (u8, u8)
{ let stdout = stdout();
  let stdin = stdin();
  let mut stdin = stdin.lock();
  let mut stdout = stdout.lock();
  print!("\x1B[6n\n");
//  stdout.write(b"\x1B[6n").unwrap();
//  stdout.flush().unwrap();
  let connard = stdin.read_pass(&mut stdout);
  let mut x: u8 = 0;
  let mut y: u8 = 0;
  let mut flag = 0;
  if let Ok(Some(connard)) = connard
  {
  for i in connard.chars()
  { if flag == 0 && i == '['
    { flag = 1; }
    else if flag == 1 && i != ';'
    { y = (y * 10) + (i as u8 - 48); }
    else if flag == 1
    { flag = 2; }
    else if flag == 2 && i != 'R'
    { x = (x * 10) + (i as u8 - 48); }
    else if flag == 2
    { flag = 3; }}
  (x, y) }
  else
  { (0, 0) }}

///structure pour conserver l'état de l'édition de ligne
pub struct Term
{ line: String, 
  prompt: String,
  curs_x: u8,
  curs_y: u8,
  begin_x: u8,
  begin_y: u8, }

fn move_it(way: u8, term: Term, buf: Vec<Key>)
{ if way == 0 && term.curs_x > term.begin_x 
  { print!("{}", Left(1)); }
  else if way == 1 && term.curs_x <= buf.len() as u8 + term.begin_x
  { print!("{}", Right(1)); }}

///command_line
pub fn command_line() -> Vec<String>
{ let stdout = stdout();
  let mut stdout = stdout.lock();
  let mut stdin = stdin();
  let coord = cursor_position();
  let mut term: Term = Term{line: String::new(), prompt: String::from("jpepin $> "), curs_x: coord.0, curs_y: coord.1, begin_x: coord.0, begin_y: coord.1};
//  println!("{}, {}", term.curs_x, term.curs_y);
//  stdout.write(b"\x1B[6n").unwrap();
  stdout.flush().unwrap();
  print!("{}", Up(1));
  print!("jpepin $> ");
  stdout.flush().unwrap();
  let mut stdout = stdout.into_raw_mode().unwrap();
  let mut buf: Vec<Key> = Vec::new();
  for c in stdin.keys()
  { let b = c.unwrap();
    term.line.push(ft_concat(b));
    match b
    { Key::Char('\n') => break,
      Key::Char('\0') => break,
      Key::Char(b) => print!("{}", b),
    //  Key::Alt(b) && Key::Up => print!("{}", Up(1)),
    //  Key::Alt(b) && Key::Down => print!("{}", Down(1)),
      Key::Alt(b) => print!("^{}", b),
      Key::Ctrl(b) => print!("*{}", b),
      Key::Left => move_it(0, term, buf),
      Key::Right => move_it(1, term, buf),
    //  Key::Up => get_history(3),
    //  Key::Down => get_history(4),
    //  Key::Backspace => del_char(),
      _ => {}, };
    stdout.flush().unwrap(); }
  split_spaces(term.line) }
