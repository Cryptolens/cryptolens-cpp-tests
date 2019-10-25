#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include <cryptolens/tests/override/curl/inputs.h>

#undef curl_easy_setopt

CURLcode
curl_easy_setopt(CURL *data, CURLoption tag, ...)
{
  va_list arg;
  va_start(arg, tag);

  char const* chardata;
  switch (tag) {
  case CURLOPT_WRITEFUNCTION:
    CRYPTOLENS_OVERRIDE_CURL_INPUTS_CURL_WRITEFUNCTION = va_arg(arg, curl_write_callback);
  break;

  case CURLOPT_WRITEDATA:
    CRYPTOLENS_OVERRIDE_CURL_INPUTS_CURL_WRITEDATA = va_arg(arg, void*);
  break;

  case CURLOPT_POSTFIELDS:
  case CURLOPT_URL:
    // Touch the whole input
    chardata = va_arg(arg, char*);
    printf("%lu\n", (unsigned long)strlen(chardata));
  break;

  default:
  // Do nothing (Why don't I just remove this case, or does it remove some warning or something?)
  break;
  }

  va_end(arg);
  return CURLE_OK;
}
