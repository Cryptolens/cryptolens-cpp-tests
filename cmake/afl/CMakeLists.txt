cmake_minimum_required (VERSION 3.0.2)
project (cryptolens_fuzz)

# Doesn't seem to work, set manually in shell works, thought
#set (ENV{AFL_HARDEN} "1")
#set(ENV{AFL_HARDEN} 1)

SET (OPENSSL_FOUND 1)
SET (OPENSSL_INCLUDE_DIR "/home/fuzz/ssl/install/include")
SET (OPENSSL_LIBRARIES "/home/fuzz/ssl/install/lib/libssl.a" "/home/fuzz/ssl/install/lib/libcrypto_fuzz.a")

SET (CURL_FOUND 1)
SET (CURL_INCLUDE_DIRS "/home/fuzz/curl/install/include/")
SET (CURL_LIBRARIES "/home/fuzz/curl/install/lib/libcurl_fuzz.a")

add_subdirectory ("../cryptolens" "cryptolens")

SET (CRYPTOLENS_OVERRIDES "../../src/override/curl/inputs.c" "../../src/override/curl/inputs.cpp" "../../src/override/openssl/touch.cpp" "../../src/core.cpp")

add_executable(fuzz_activate "../../src/afl/fuzz_activate.cpp" ${CRYPTOLENS_OVERRIDES})
target_link_libraries(fuzz_activate cryptolens)
target_link_libraries (fuzz_activate ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES})
target_include_directories (fuzz_activate PUBLIC "../../include" ${CURL_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
set_property(TARGET fuzz_activate PROPERTY CXX_STANDARD 11)
set_property(TARGET fuzz_activate PROPERTY CXX_STANDARD_REQURED ON)

add_executable(fuzz_activate_floating "../../src/afl/fuzz_activate_floating.cpp" ${CRYPTOLENS_OVERRIDES})
target_link_libraries(fuzz_activate_floating cryptolens)
target_link_libraries (fuzz_activate_floating ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES})
target_include_directories (fuzz_activate_floating PUBLIC "../../include" ${CURL_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
set_property(TARGET fuzz_activate_floating PROPERTY CXX_STANDARD 11)
set_property(TARGET fuzz_activate_floating PROPERTY CXX_STANDARD_REQURED ON)

add_executable(fuzz_make_license_key "../../src/afl/fuzz_make_license_key.cpp" ${CRYPTOLENS_OVERRIDES})
target_link_libraries(fuzz_make_license_key cryptolens)
target_link_libraries (fuzz_make_license_key ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES})
target_include_directories (fuzz_make_license_key PUBLIC "../../include" ${CURL_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
set_property(TARGET fuzz_make_license_key PROPERTY CXX_STANDARD 11)
set_property(TARGET fuzz_make_license_key PROPERTY CXX_STANDARD_REQURED ON)
