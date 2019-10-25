#include <cryptolens/tests/core.hpp>
#include <cryptolens/tests/override/curl/inputs.h>
#include <cryptolens/tests/override/curl/inputs.hpp>

namespace cryptolens_io {

namespace tests {

namespace override {

namespace curl {

namespace inputs {

std::deque<std::string> inputs;

} // namespace inputs

} // namespace curl

} // namespace override

} // namespace tests

} // namespace cryptolens_io

curl_write_callback CRYPTOLENS_OVERRIDE_CURL_INPUTS_CURL_WRITEFUNCTION = nullptr;
void * CRYPTOLENS_OVERRIDE_CURL_INPUTS_CURL_WRITEDATA = nullptr;

CURLcode
curl_easy_perform(CURL * easy_handle)
{
  for (auto & s : cryptolens_io::tests::override::curl::inputs::inputs) {
    (*CRYPTOLENS_OVERRIDE_CURL_INPUTS_CURL_WRITEFUNCTION)((char*)s.c_str(), 1, s.size(), CRYPTOLENS_OVERRIDE_CURL_INPUTS_CURL_WRITEDATA);
  }

  return CURLE_OK;
}
