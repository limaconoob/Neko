use ::std::collections::VecDeque;

pub struct Log {
  output: VecDeque<u8>,
}

impl Log {
  fn len(&self) -> usize {
    self.output.len()
  }

  fn capacity(&self) -> usize {
  self.output.capacity()
  }

  fn pop_front(&mut self) -> Option<u8> {
    self.output.pop_front()
  }
}

impl Extend<u8> for Log {
  fn extend<T: IntoIterator<Item=u8>>(&mut self, iter: T) {
    self.output.extend(iter);
    if let Some(len) = 4096usize.checked_sub(self.len()) {
      assert!((0..len).all(|_| self.pop_front().is_some()));
    }
  }
}

impl Default for Log {
  fn default() -> Log {
    Log {
      output: VecDeque::with_capacity(4096),
    }
  }
}
