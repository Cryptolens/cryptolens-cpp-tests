#include <cryptolens/tests/core.hpp>

#ifndef _WIN32
#include <unistd.h>
#endif

namespace cryptolens_io {

namespace tests {

CharReader::CharReader() : buf_(), pos_(0), size_(0) { read_(); }

CharReader::operator bool() const { return !(pos_ == 1 && size_ == 0); }

void CharReader::read_() {
#ifndef _WIN32
  size_ = read(0, &buf_, BUFSIZE);
  if (size_ == 0) { pos_ = 1; }
#endif
}

std::deque<std::string>
read_inputs()
{
  std::deque<std::string> inputs;
  CharReader in;

  split_input<'@', '!'>(in, std::back_inserter(inputs));

  return inputs;
}

CharReader &
operator>>(CharReader & in, char & c)
{
  c = in.buf_[in.pos_];
  ++in.pos_;

  if (in.pos_ >= in.size_) { in.read_(); }

  return in;
}

} // namespace tests

} // namespace cryptolens_io
