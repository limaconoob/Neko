use termion::event::{Event,Key};
use termion::cursor::{Up,Down,Goto};
use termion::raw::IntoRawMode;
use std::io::prelude::*;
use std::io::{stdout,stdin,self};

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

pub struct Neko
{ //pub image: Vec<Vec<char>>,
  pub tmp_char: u8,
  pub char_exe: char,
  pub coord_exe: (u16, u16),
  pub event: Event,
  pub coord: (u16, u16),
  pub size: (u16, u16),
  pub term: (u16, u16), }

pub trait NekoInfo
{ fn display(&self);
  fn switch(&mut self);
  fn erase(&self); }

impl Neko
{ pub fn new(coord: (u16, u16), size: (u16, u16), the: &mut Term, term: (u16, u16)) -> Self
  { let mut i = 0;
    while i < size.1 && coord.1 + i < term.1
    { print!("{}", Goto(coord.0, coord.1 + i + 1));
      i += 1;
      let mut j = 0;
      while j < size.0 && j + coord.0 <= term.0
      { the.matrix[i as usize][j as usize] = 4;
        j += 1;
        print!("{}", '!'); }}
    Neko
    { coord: coord,
      size: size,
      char_exe: 'j',
      coord_exe: (1, 2),
      tmp_char: '!' as u8,
      event: Event::Key(Key::Char('\0')),
      term: term, }}}

impl NekoInfo for Neko
{ fn display(&self)
  { let mut i = 0;
    while i < self.size.1 && self.coord.1 + i < self.term.1
    { print!("{}", Goto(self.coord.0, self.coord.1 + i + 1));
      i += 1;
      let mut j = 0;
      while j < self.size.0 && j + self.coord.0 <= self.term.0
      { j += 1;
        print!("{}", self.tmp_char as char); }}
    print!("{}{}", Goto(self.coord.0 + self.coord_exe.0, self.coord.1 + self.coord_exe.1), self.char_exe); }
  fn switch(&mut self)
  { if self.tmp_char <= 126
    { self.tmp_char += 1; }
    else
    { self.tmp_char = 33; }}
  fn erase(&self)
  { let mut i = 0;
    print!("{}", Goto(self.coord.0, self.coord.1 + 1));
    let mut eraser: String = String::with_capacity(self.size.0 as usize);
    while i < self.size.0
    { i += 1;
      eraser.push(' '); }
      i = 0;
      while i < self.size.1 && self.coord.1 + i < self.term.1
      { print!("{}", Goto(self.coord.0, self.coord.1 + i + 1));
        i += 1;
        print!("{}{}", eraser, Down(1)); }
        if self.coord.1 + self.size.1 == self.term.1
        { println!(""); }
        print!("{}", Up(self.size.1)); }}

pub struct Term
{ pub matrix: Vec<Vec<u8>>,
  pub curs_x: u16,
  pub curs_y: u16,
  pub begin_x: u16,
  pub begin_y: u16, }

pub trait TermInfo
{ fn cursor_position(&self) -> io::Result<(u16, u16)>;
  fn go_to_curs(&self); }

impl Term
{ pub fn new() -> Self
  { Term
    { matrix: Vec::new(),
      curs_x: 0,
      curs_y: 0,
      begin_x: 0,
      begin_y: 0, }}}

impl TermInfo for Term
{ fn cursor_position(&self) -> io::Result<(u16, u16)>
  { let stdout = stdout();
    let stdin = stdin();
    let mut stdin = stdin.lock();
    let mut stdout = stdout.lock();
    print!("\x1B[6n\n");
    let connard = stdin.read_pos(&mut stdout);
    let mut x: u16 = 0;
    let mut y: u16 = 0;
    let mut flag = 0;
    if let Ok(Some(connard)) = connard
    { for i in connard.chars()
      { if flag == 0 && i == '['
        { flag = 1; }
        else if flag == 1 && i != ';'
        { y = (y * 10) + (i as u16 - 48); }
        else if flag == 1
        { flag = 2; }
        else if flag == 2 && i != 'R'
        { x = (x * 10) + (i as u16 - 48); }
        else if flag == 2
        { flag = 3; }}
        Ok((x, y)) }
    else
    { Ok((0, 0)) }}
  fn go_to_curs(&self)
  { print!("{}", Goto(self.curs_x, self.curs_y)); }}
