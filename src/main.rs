#[macro_use]
extern crate clap;
extern crate neko;

use std::env;

use neko::page::Page;

use neko::pty;
use neko::pty_shell::{
  PtyShell,
};

fn main() {
  let yaml = load_yaml!("cli.yml");
  let options = clap::App::from_yaml(yaml).get_matches();

  let shell: &str = &match options.value_of("shell") {
    Some(shell) => shell.to_string(),
    None => env::var("SHELL").expect("The `--shell` option or `$SHELL` variable of environement must be defined"),
  };
  let page: Page = match options.value_of("limit") {
    Some(limit) => Page::new(
      limit.parse::<usize>().expect("The limit of argument must be a natural integer")
    ),
    None => Page::default(),
  };
  let child = pty::fork().unwrap();

  child.exec(shell).unwrap();
  child.proxy(page).unwrap();
  child.wait().unwrap();
}
