
extern crate ms;
extern crate termion;

use std::io::{stdout};
use std::io::prelude::*;
use termion::terminal_size;
use ms::objets::{Neko,Term,TermInfo};

//use std::env;
use ms::get_line::command_line;

/*
fn exit(flag:i8)->!
{ if flag == 0
  { panic!("Brauch Argumente!") }
  else if flag == 1
  { panic!("Connard") }
  panic!("") }
*/
/*
{ let args: Vec<_> = env::args().collect();
   let len = args.len();
   if len == 1
   { exit(0); }}
*/

fn main()
{ let stdout = stdout();
  let mut stdout = stdout.lock();
  let t_size = terminal_size().unwrap();
  let ref mut term: Term = Term::new();
  let coord = term.cursor_position().unwrap();
  let size = (8, 5);
  let mut i = 0;
  while i < t_size.1
  { let mut j = 0;
    let mut coucou: Vec<u8> = Vec::new();
    while j < t_size.0
    { coucou.push(0); 
      j += 1; }
    term.matrix.push(coucou); 
    i += 1; }
  let ref mut neko: Neko = Neko::new(coord, size, t_size);
/*  for k in term.matrix.clone()
  { print!("[");
    for u in k
    { print!("{}, ", u); }
    println!("]"); } */
  let coord = term.cursor_position().unwrap();
  term.curs_x = 1;
  term.curs_y = coord.1 + 1;
  term.begin_x = 1;
  term.begin_y = coord.1 + 1;
  stdout.flush().unwrap();
  loop
  { let tmp = command_line(neko, term); 
    for i in tmp
    { if i == "exit"
      { return }}}}
