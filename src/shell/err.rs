use ::pty::prelude::ForkError;

//use std::fmt;
//use std::error::Error;

pub type Result<T> = ::std::result::Result<T, ShellError>;

/// The enum `ShellError` defines the possible errors from constructor Shell.

#[derive(Clone, Copy, Debug)]
pub enum ShellError {
  BadFork(ForkError),
}
