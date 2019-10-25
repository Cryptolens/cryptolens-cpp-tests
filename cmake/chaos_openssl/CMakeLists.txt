cmake_minimum_required (VERSION 3.0.2)
project (cryptolens_chaos_openssl)

set (OPENSSL_FOUND 1)
set (OPENSSL_INCLUDE_DIR "/home/fuzz/ssl/install/include")
set (OPENSSL_LIBRARIES "/home/fuzz/ssl/install/lib/libssl.a" "/home/fuzz/ssl/install/lib/libcrypto_chaos.a")

set (CURL_FOUND 1)
set (CURL_INCLUDE_DIRS "/home/fuzz/curl/install/include/")
set (CURL_LIBRARIES "/home/fuzz/curl/install/lib/libcurl.a")

add_subdirectory ("../cryptolens" "cryptolens")

set (CRYPTOLENS_OVERRIDES "../../src/override/openssl/chaos.cpp")

add_executable(openssl_activate_external "../src/chaos/openssl_activate_external.cpp" ${CRYPTOLENS_OVERRIDES})
target_link_libraries(openssl_activate_external cryptolens)
target_link_libraries (openssl_activate_external ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES})
target_include_directories (openssl_activate_external PUBLIC "../../include" ${CURL_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
set_property(TARGET openssl_activate_external PROPERTY CXX_STANDARD 11)
set_property(TARGET openssl_activate_external PROPERTY CXX_STANDARD_REQURED ON)
