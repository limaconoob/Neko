
extern crate ms;

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
{ loop
  { let tmp = command_line(); 
    for i in tmp
    { if i == "exit"
      { return }
      else
      { print!("{}, ", i); }}}}
