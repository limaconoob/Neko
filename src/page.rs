use ::pty_shell::{winsize, PtyShell, PtyHandler};
use ::std::collections::VecDeque;

struct Page {
  lines: VecDeque<Vec<u8>>,
  size: winsize::Winsize,
}

impl Page {
  pub fn new(limit: usize) -> Self {
    Page {
      lines: VecDeque::with_capacity(limit),
      size: winsize::Winsize::default(),
    }
  }

  pub fn push(&mut self, line: Vec<u8>) {
    if self.lines.capacity() >= self.lines.len() {
      self.lines.pop_front();
    }
    self.lines.push_back(line);
  }
}

impl PtyHandler for Page {
  fn input(&mut self, input: &[u8]) {
    self.push(input.to_vec());
  }

  fn output(&mut self, output: &[u8]) {
    self.push(output.to_vec());
  }

  fn resize(&mut self, winsize: &winsize::Winsize) {
    self.size = winsize.clone();
  }

  fn shutdown(&mut self) {
  }
}
