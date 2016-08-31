use ::pty::prelude as pty;
use ::libc;

use std::ffi::CString;
use std::ptr;

pub trait Child {
  fn exec(&self, &'static str) -> !;
}

impl Child for pty::Slave {
  fn exec(&self, command: &'static str) -> ! {
    let mut ptrs = [
      CString::new(command).unwrap().as_ptr(),
      ptr::null(),
    ];

    unsafe {
      libc::execvp(*ptrs.as_ptr(), ptrs.as_mut_ptr());
    }
    unimplemented!();
  }
}
