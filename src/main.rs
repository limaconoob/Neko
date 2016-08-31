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
      let a = rx1.iter().zip(rx2.clone()).map(|((x, u), (xx, uu))| {
        io::stdout().write(&x[..u]).unwrap();
        io::stdout().flush().unwrap();

        println!("{}-{}", u, uu);
        master.write(&xx[..uu]).unwrap();
        master.flush().unwrap();

        String::from_utf8_lossy(&x[..u]).into_owned()
      }).collect::<Vec<String>>();
      println!("{:?}", a);
/*
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

//         println!("{}", std::str::from_utf8(&bytes[..read]).unwrap());
          if &bytes[..read] == b"exit\n" {
            master.write(b"echo nop\n").unwrap(); // troll
          }
          else {
            master.write(&bytes[..read]).unwrap();
          }
          master.flush().unwrap();
          println!("a")
        }
      }*/
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
