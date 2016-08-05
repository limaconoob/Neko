///nope

use std::io::{stdout, stdin, self};
use std::io::prelude::*;
use termion::event::Key;
use termion::cursor::{Left,Right,Up};
use termion::input::TermRead;
use termion::raw::IntoRawMode;
use parse::{split_spaces,ft_concat};
use std::fmt;

trait Bonjour
{ fn curs_pos(&mut self) -> io::Result<Option<String>>;
  fn read_pos<W: Write>(&mut self, writer: &mut W) -> io::Result<Option<String>>
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

///structure pour conserver l'état de l'édition de ligne
struct Term
{ line: Vec<String>,
  prompt: String,
  curs_x: u8,
  curs_y: u8,
  begin_x: u8,
  begin_y: u8,
  term_x: u8,
  term_y: u8, }

trait TermInfo
{ fn cursor_position(&self) -> (u8, u8); }

impl Term
{ fn new(prompt: String) -> Self
  { Term
    { line: Vec::new(),
      prompt: prompt,
      curs_x: 0,
      curs_y: 0,
      begin_x: 0,
      begin_y: 0,
      term_x: 0,
      term_y: 0, }}}

impl TermInfo for Term
{ fn cursor_position(&self) -> (u8, u8)
  { let stdout = stdout();
    let stdin = stdin();
    let mut stdin = stdin.lock();
    let mut stdout = stdout.lock();
    print!("\x1B[6n\n");
    let connard = stdin.read_pos(&mut stdout);
    let mut x: u8 = 0;
    let mut y: u8 = 0;
    let mut flag = 0;
    if let Ok(Some(connard)) = connard
    { for i in connard.chars()
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
      { (0, 0) }}}

fn move_it(way: u8)
{ if way == 0
  { print!("{}", Left(1)); }
  else if way == 1
  { print!("{}", Right(1)); }}

fn move_to(way: i16)
{ if way > 0
  { print!("{}", Right(way as u16)); }
  else if way < 0
  { print!("{}", Left((way * -1) as u16)); }}

///command_line
pub fn command_line() -> Vec<String>
{ let stdout = stdout();
  let mut stdout = stdout.lock();
  let mut stdin = stdin();
  print!("jpepin $> ");
  let ref mut term: Term = Term::new(String::from("jpepin $> "));
  let coord = term.cursor_position();
  term.curs_x = coord.0;
  term.curs_y = coord.1;
  term.begin_x = coord.0;
  term.begin_y = coord.1;
//  let ref mut term: Term = Term{line: Vec::new(), prompt: String::from("jpepin $> "), curs_x: coord.0, curs_y: coord.1, begin_x: coord.0, begin_y: coord.1};
  stdout.flush().unwrap();
  print!("{}{}", Up(1), Right(term.prompt.len() as u16));
  stdout.flush().unwrap();
  let mut stdout = stdout.into_raw_mode().unwrap();
  let mut buf: Vec<char> = Vec::new();
  let mut size = 0;
  for c in stdin.keys()
  { let b = c.unwrap();
    match b
    { Key::Char('\n') =>  break,
      Key::Char('\0') =>  break,
      Key::Char(b) =>   { term.curs_x += 1;
                          size += 1;
                          buf.push(b);
                          print!("{}", b) },
    //  Key::Alt(b) && Key::Up => print!("{}", Up(1)),
    //  Key::Alt(b) && Key::Down => print!("{}", Down(1)),
      Key::Alt(b) =>    { term.curs_x += 2;
                          size += 1;
                          buf.push(b);
                          print!("^{}", b) },
      Key::Ctrl(b) =>   { term.curs_x += 2;
                          size += 1;
                          buf.push(b);
                          print!("*{}", b) },
      Key::Left =>      if term.curs_x > term.begin_x
                        { term.curs_x -= 1;
                          move_it(0) },
      Key::Right =>     if term.curs_x < size + term.begin_x
                        { term.curs_x += 1;
                          move_it(1) },
      Key::Backspace => if size > 0 && term.curs_x > term.begin_x
                        { size -= 1;
                          term.curs_x -= 1;
                          move_it(0);
                          buf.remove((term.curs_x - term.begin_x) as usize);
                          let mut u: Vec<_> = buf.drain(((term.curs_x - term.begin_x) as usize)..).collect();
                          let mut j = u.clone();
                          let taille = u.len();
                       //   print!("taille::{}", (taille as i16) * -1);
                          for i in u
                          { print!("{}", i); }
                          buf.append(&mut j);
                          print!(" ");
                          move_to((taille as i16) * -1);
                          move_it(0) },
    //  Key::Up => get_history(3),
    //  Key::Down => get_history(4),
      _ => {}, };
    stdout.flush().unwrap(); }
  //println!("\n\rbegin_x::{}, size::{}", term.begin_x, size);
  split_spaces(ft_concat(buf)) }
