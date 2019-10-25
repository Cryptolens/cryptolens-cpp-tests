cmake_minimum_required (VERSION 3.0.2)
project (cryptolens_gtest)

SET (OPENSSL_FOUND 1)
SET (OPENSSL_INCLUDE_DIR "/home/fuzz/ssl/install/include")
SET (OPENSSL_LIBRARIES "/home/fuzz/ssl/install/lib/libssl.a" "/home/fuzz/ssl/install/lib/libcrypto.a")

SET (CURL_FOUND 1)
SET (CURL_INCLUDE_DIRS "/home/fuzz/curl/install/include/")
SET (CURL_LIBRARIES "/home/fuzz/curl/install/lib/libcurl.a")

add_subdirectory ("../cryptolens" "cryptolens")

file(GLOB test_sources "../../src/gtest/generated/*.cpp")
set (test_sources "../../src/gtest/tests_main.cpp" "../../src/gtest/tests.cpp" ${test_sources})
add_executable(cryptolens_gtest ${test_sources})
target_link_libraries(cryptolens_gtest cryptolens)
target_link_libraries (cryptolens_gtest ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES})
target_link_libraries (cryptolens_gtest "/home/fuzz/googletest/googletest/build/lib/libgtest.a")
target_link_libraries (cryptolens_gtest "dl" "pthread")
target_include_directories (cryptolens_gtest PUBLIC "../../include" "/home/fuzz/googletest/googletest/include" ${CURL_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
set_property(TARGET cryptolens_gtest PROPERTY CXX_STANDARD 11)
set_property(TARGET cryptolens_gtest PROPERTY CXX_STANDARD_REQURED ON)
