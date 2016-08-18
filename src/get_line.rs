///nope

use std::io::{stdout,stdin};
use std::io::prelude::*;
use termion::event::{Event,Key,MouseButton,MouseEvent};
use termion::cursor::{Left,Right};
use termion::input::{TermRead,MouseTerminal};
use termion::raw::IntoRawMode;
use parse::{split_spaces,ft_concat};
use objets::{Neko,Term,TermInfo,NekoInfo};

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
pub fn command_line(neko: &mut Neko, term: &mut Term) -> Vec<String>
{ let stdout = stdout();
  let mut stdout = stdout.lock();
  let stdin = stdin();
//  print!("\x1B[u");
//  print!("{}{}", Right(neko.size.0), Down(neko.size.1));
  neko.display(term);
  stdout.flush().unwrap();
  term.go_to_curs();
  stdout.flush().unwrap();
  let mut stdout = MouseTerminal::from(stdout.into_raw_mode().unwrap());
  let mut buf: Vec<char> = Vec::new();
  let mut size = 0;
  let mut flag;
  for c in stdin.events()
  { let b = c.unwrap();
    neko.event = b;
    flag = 0;
    match b
    { Event::Key(Key::Char('\n')) => break,
      Event::Key(Key::Char('\0')) => break,
      Event::Key(Key::Char(b)) => { size += 1;
                          buf.push(b);
                          term.matrix[term.curs_y as usize - 1][term.curs_x as usize - 1] = b as u8;
                          term.curs_x += 1;
                          print!("{}", b) },
      Event::Key(Key::Left) => if term.curs_x > term.begin_x
                        { term.curs_x -= 1;
                          move_it(0) },
      Event::Key(Key::Right) => if term.curs_x < size + term.begin_x
                        { term.curs_x += 1;
                          move_it(1) },
      Event::Key(Key::Backspace) => if size > 0 && term.curs_x > term.begin_x
                        { size -= 1;
                          term.curs_x -= 1;
                          move_it(0);
                          buf.remove((term.curs_x - term.begin_x) as usize);
                          let ref mut u: Vec<_> = buf.drain(((term.curs_x - term.begin_x) as usize)..).collect();
                          let mut j = u.clone();
                          let taille = u.len();
                          for i in u
                          { print!("{}", i); }
                          buf.append(&mut j);
                          print!(" ");
                          move_to((taille as i16) * -1);
                          move_it(0) },
      Event::Mouse(me) => { match me
                            { MouseEvent::Press(_, a, b) =>
                              { if a >= neko.coord.0 && a <= neko.coord.0 + neko.size.0 && b > neko.coord.1 && b <= neko.coord.1 + neko.size.1
                              { /*print!("NEKOPress  ");*/ }}
                              MouseEvent::Release(a, b) =>
                              { if a >= neko.coord.0 && a <= neko.coord.0 + neko.size.0 && b > neko.coord.1 && b <= neko.coord.1 + neko.size.1
                              { /*print!("NEKORelease");*/ }}
                              MouseEvent::Drag(MouseButton::ShiftLeftDrag, a, b) =>
                              { neko.erase(term);
                                flag = 1;
                                neko.coord.0 = a;
                                neko.coord.1 = b - 1; }
                              _ => {}, }}
    //  Event::Key(Key::Alt(b)) && Key::Up => print!("{}", Up(1)),
    //  Event::Key(Key::Alt(b)) && Key::Down => print!("{}", Down(1)),
      Event::Key(Key::Alt(b)) => { term.curs_x += 2;
                          size += 1;
                          buf.push(b);
                          print!("^{}", b) },
      Event::Key(Key::Ctrl(b)) => { term.curs_x += 2;
                          size += 1;
                          buf.push(b);
                          print!("*{}", b) },
      Event::Key(Key::Up) => 
      {  for k in term.matrix.clone()
        { print!("[");
            for u in k
                  { print!("{}, ", u); }
                      println!("]"); } },
    //  Event::Key(Key::Up) => get_history(3),
    //  Event::Key(Key::Down) => get_history(4),
      _ => {}, };
    if flag == 0
    { neko.erase(term); }
    neko.switch();
    neko.display(term);
    term.go_to_curs();
    stdout.flush().unwrap(); }
  print!("\n\r");
  let coord = term.cursor_position().unwrap();
  term.curs_x = coord.0;
  term.curs_y = coord.1;
  term.begin_x = coord.0;
  term.begin_y = coord.1;
  neko.erase(term);
//  print!("\x1B[s\r{}", Right(neko.size.0));
  split_spaces(ft_concat(buf)) }
