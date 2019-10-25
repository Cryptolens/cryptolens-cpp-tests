#include <curl/curl.h>

#include <cryptolens/tests/core.hpp>

#define curl_easy_init() ((cryptolens_io::tests::override::curl::chaos::chaos->should_fail()) ? NULL : curl_easy_init())
#define curl_easy_escape(ASDF, string, length) ((cryptolens_io::tests::override::curl::chaos::chaos->should_fail()) ? NULL : curl_easy_escape((ASDF), (string), (length)))
#define curl_easy_setopt(handle, option, ...) ((cryptolens_io::tests::override::curl::chaos::chaos->should_fail()) ? CURLE_AGAIN : curl_easy_setopt((handle), (option), __VA_ARGS__))
#define curl_easy_perform(easy_handle) ((cryptolens_io::tests::override::curl::chaos::chaos->should_fail()) ? CURLE_AGAIN : curl_easy_perform((easy_handle)))
