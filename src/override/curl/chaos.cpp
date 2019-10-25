#include <stdio.h>
#include <stdlib.h>

#include <cryptolens/imports/curl/curl.h>

#include <cryptolens/tests/core.hpp>

namespace cryptolens_io {

namespace tests {

namespace override {

namespace curl {

namespace chaos {

Chaos * chaos = nullptr;

} // namespace chaos

} // namespace curl

} // namespace override

} // namespace tests

} // namespace cryptolens_io

#if 0

extern "C" {

CURL* r_curl_easy_init();
char * r_curl_easy_escape(CURL * curl, char const* string, int length);
CURLcode r_curl_easy_setopt(CURL * handle, CURLoption option, ...);
CURLcode r_curl_easy_perform(CURL * easy_handle);

CURL *
curl_easy_init()
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return r_curl_easy_init();
}

char *
curl_easy_escape(CURL * curl, char const* string, int length)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return r_curl_easy_escape(curl, string, length);
}

CURLcode
curl_easy_perform(CURL * easy_handle)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return CURLE_AGAIN;
  }

  return r_curl_easy_perform(easy_handle);
}

} // extern "C"

#endif
