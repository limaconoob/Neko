
use std::io::{stdout};
use std::io::prelude::*;
use termion::terminal_size;
use objets::{Neko,Term,TermInfo};
use get_line::command_line;

fn the_neko(matrix: Vec<Vec<u8>>)
{ let stdout = stdout();
  let mut stdout = stdout.lock();
  let t_size = terminal_size().unwrap();
  let ref mut term: Term = Term::new();
  let coord = term.cursor_position().unwrap();
  let size = (8, 5);
  let mut i = 0;
  term.matrix = matrix;
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
