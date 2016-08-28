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
    let (tx1, rx1) = chan::sync(0);
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
      chan_select! {
        rx1.recv() -> val => {
          let (bytes, read): ([u8; 4096], usize) = val.unwrap(); // read master output from child process

          io::stdout().write(&bytes[..read]).unwrap();
          io::stdout().flush().unwrap();
        },
        rx2.recv() -> val => { // read stardard input command
          let (bytes, read): ([u8; 4096], usize) = val.unwrap();

          if &bytes[..read] == b"exit\n" {
            master.write(b"echo nop\n").unwrap();
          }
          else {
          master.write(&bytes[..read]).unwrap();
          }
          master.flush().unwrap();
        }
      }
    }
  }
  else {
    let mut ptrs = [CString::new("bash").unwrap().as_ptr(), ptr::null()];

    let _ = unsafe { libc::execvp(*ptrs.as_ptr(), ptrs.as_mut_ptr()) };
  }
}
