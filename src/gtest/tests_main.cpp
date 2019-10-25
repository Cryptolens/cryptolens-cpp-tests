#include <curl/curl.h>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  curl_global_init(CURL_GLOBAL_SSL);

  ::testing::InitGoogleTest(&argc, argv);
  auto result = RUN_ALL_TESTS();

  curl_global_cleanup();

  return result;
}
