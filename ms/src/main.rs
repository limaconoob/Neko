
extern crate ms;

use std::env;
use ms::get_line::command_line;

fn exit(flag:i8)->!
{ if flag == 0
  { panic!("Brauch Argumente!") }
  else if flag == 1
  { panic!("Connard") }
  panic!("") }

fn main()
{ let args: Vec<_> = env::args().collect();
   let len = args.len();
   if len == 1
   { exit(0); }
//   let mut i = 1;
//   while i < len
//   { println!("arg[{}]::{}", i - 1, args[i]); 
//     i+=1; }
   loop
   { let tmp = command_line(); 
     print!("\n\r");
     for i in tmp
     { if i == "exit"
         {return} ;
       print!("[{}] ", i); }
     print!("\n\r"); }}
