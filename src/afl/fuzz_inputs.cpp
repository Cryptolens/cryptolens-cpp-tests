#include <iostream>

#include <cryptolens/tests/core.hpp>

int main()
{
#if 1 && defined(__AFL_HAVE_MANUAL_CONTROL)
  __AFL_INIT();

  while(__AFL_LOOP(1000))
#else
  for (int i = 0; i < 1; ++i)
#endif
  {
    auto inputs = cryptolens_io::tests::read_inputs();
    for (auto const& s : inputs) { std::cout << s << std::endl; }
  }

  return 0;
}
