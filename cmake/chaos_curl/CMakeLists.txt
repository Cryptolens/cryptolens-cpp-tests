cmake_minimum_required (VERSION 3.0.2)
project (cryptolens_chaos_curl)

set (OPENSSL_FOUND 1)
set (OPENSSL_INCLUDE_DIR "/home/fuzz/ssl/install/include")
set (OPENSSL_LIBRARIES "/home/fuzz/ssl/install/lib/libssl.a" "/home/fuzz/ssl/install/lib/libcrypto.a")

set (CURL_FOUND 1)
set (CURL_INCLUDE_DIRS "/home/fuzz/curl/install/include/")
set (CURL_LIBRARIES "/home/fuzz/curl/install/lib/libcurl.a")

set (CRYPTOLENS_PUBLIC_INCLUDE_DIRS "/work/tests/include" "/work/tests/include/cryptolens")
set (CRYPTOLENS_PRIVATE_INCLUDE_DIRS "/work/tests/include" "/work/tests/include/cryptolens")

add_subdirectory ("../cryptolens" "cryptolens")

set (CRYPTOLENS_OVERRIDES "../src/override/curl/chaos.cpp")

add_executable (curl_activate "../src/chaos/curl_activate_external.cpp" ${CRYPTOLENS_OVERRIDES})
target_link_libraries (curl_activate cryptolens)
target_link_libraries (curl_activate ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES})
target_include_directories (curl_activate PUBLIC "../../include" ${CURL_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
set_property (TARGET curl_activate PROPERTY CXX_STANDARD 11)
set_property (TARGET curl_activate PROPERTY CXX_STANDARD_REQURED ON)
