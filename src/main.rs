/*extern crate neko;

use neko::shell::Shell;

fn main() {
  let mut shell: Shell = Shell::new(None).unwrap();

  while let Some(key) = shell.next() {
//    println!("-> '{}'", key as char);
  }
}
*/


#[macro_use(chan_select)]
extern crate chan;
extern crate pty;
extern crate libc;

use pty::prelude::*;

use std::io::prelude::*;
use std::io;

use std::ffi::CString;
use std::{ptr, thread};

fn main() {
  let fork = Fork::from_ptmx().unwrap();

  if let Some(mut master) = fork.is_father().ok() {
    let (tx1, rx1): (chan::Sender<([u8; 4096], usize)>, chan::Receiver<([u8; 4096], usize)>) = chan::sync(0);
    let (tx2, rx2) = chan::sync(0);

    thread::spawn(move || {
      let mut bytes = [0u8; 4096];
      loop {
        let read = master.read(&mut bytes).unwrap();

        tx1.send((bytes, read));
      }
    });
    thread::spawn(move || {
      let mut bytes = [0u8; 4096];
      loop {
        let read = io::stdin().read(&mut bytes).unwrap();

        tx2.send((bytes, read));
      }
    });
    
    loop {
      while let Some((bytes, read)) = rx1.iter().next() {
        if read == 0 {
          return ;
        }
        else {
          io::stdout().write(&bytes[..read]).unwrap();
          io::stdout().flush().unwrap();
          break ;
        }
      }
      while let Some((bytes, read)) = rx2.iter().next() {
        master.write(&bytes[..read]).unwrap();
        master.flush().unwrap();
        break ;
      }
    }
  }
  else {
    let mut ptrs = [CString::new("bash").unwrap().as_ptr(), ptr::null()];

    unsafe {
      libc::execvp(*ptrs.as_ptr(), ptrs.as_mut_ptr());
    };
    unimplemented!();
  }
}
/*
#[macro_use(chan_select)]
extern crate chan;
extern crate pty;
extern crate libc;

use pty::prelude::*;

use std::io::prelude::*;
use std::io;

use std::ffi::CString;
use std::{ptr, thread};

fn main() {
  let fork = Fork::from_ptmx().unwrap();

  if let Some(mut master) = fork.is_father().ok() {
    let (tx1, rx1): (chan::Sender<([u8; 4096], usize)>, chan::Receiver<([u8; 4096], usize)>) = chan::sync(0);
    let (tx2, rx2) = chan::sync(0);

    thread::spawn(move || {
      let mut bytes = [0u8; 4096];
      loop {
        let read = master.read(&mut bytes).unwrap();

        tx1.send((bytes, read));
      }
    });
    thread::spawn(move || {
      let mut bytes = [0u8; 1];
      loop {
        let read = io::stdin().read(&mut bytes).unwrap();

        tx2.send((bytes, read));
      }
    });

    loop {
      chan_select! {
        rx1.recv() -> val => {
          let (bytes, read): ([u8; 4096], usize) = val.unwrap(); // read master output from child process

          if read == 0 { // check if the child is dead
            unsafe {
              libc::exit(0);
            }
          }
          else {
            io::stdout().write(&bytes[..read]).unwrap(); // print both output of prompt and command
            io::stdout().flush().unwrap();
          }
        },
        rx2.recv() -> val => { // read the stardard input command when it's send
          let (bytes, read): ([u8; 1], usize) = val.unwrap();

          master.write(&bytes[..read]).unwrap();
          master.flush().unwrap();
        }
      }
    }
  }
  else {
    let mut ptrs = [CString::new("bash").unwrap().as_ptr(), ptr::null()];

    unsafe {
      libc::execvp(*ptrs.as_ptr(), ptrs.as_mut_ptr());
    };
    unimplemented!();
  }
}*/
