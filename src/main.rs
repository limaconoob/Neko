#[macro_use(chan_select)]
extern crate chan;
extern crate pty;
extern crate libc;
extern crate termios;

use pty::prelude::*;

use termios::*;

use std::io::prelude::*;
use std::io;

use std::ffi::CString;
use std::{ptr, thread};

fn init_term() {
    let mut term = Termios::from_fd(0).unwrap();
    term.c_lflag &= !(ECHO | ICANON | ECHONL | ISIG | IEXTEN);
    term.c_iflag &= !(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    term.c_cflag &= !(CSIZE | PARENB);
    term.c_cflag |= CS8;
    term.c_oflag &= !OPOST;
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &mut term).unwrap();
}

fn main() {
  let fork = Fork::from_ptmx().unwrap();

  if let Some(mut master) = fork.is_father().ok() {
    init_term();
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

          if read == 0 { // check if the child is dead
            break ;
          }
          else {
            io::stdout().write(&bytes[..read]).unwrap(); // print both output of prompt and command
            io::stdout().flush().unwrap();
          }
        },
        rx2.recv() -> val => { // read the stardard input command when it's send
          let (bytes, read): ([u8; 4096], usize) = val.unwrap();

          if &bytes[..read] == b"exit\n" {
            master.write(b"echo nop\n").unwrap(); // troll
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

    unsafe {
      libc::execvp(*ptrs.as_ptr(), ptrs.as_mut_ptr());
    };
  }
}
