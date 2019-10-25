cmake_minimum_required (VERSION 3.0.2)
project (cryptolens)

set (CRYPTOLENS_CURL_EMBED_CACERTS OFF CACHE BOOL "embed the ca certs in the library instead of using system default files?")

if (NOT (${CRYPTOLENS_ROOT}))
  set (CRYPTOLENS_ROOT "../../../")
endif ()

set (CRYPTOLENS_SRC ${CRYPTOLENS_SRC} "${CRYPTOLENS_ROOT}/src/ActivateError.cpp" "${CRYPTOLENS_ROOT}/src/DataObject.cpp" "${CRYPTOLENS_ROOT}/src/LicenseKey.cpp" "${CRYPTOLENS_ROOT}/src/LicenseKeyChecker.cpp" "${CRYPTOLENS_ROOT}/src/LicenseKeyInformation.cpp" "${CRYPTOLENS_ROOT}/src/MachineCodeComputer_static.cpp" "${CRYPTOLENS_ROOT}/src/RawLicenseKey.cpp" "${CRYPTOLENS_ROOT}/src/ResponseParser_ArduinoJson5.cpp" "${CRYPTOLENS_ROOT}/src/basic_SKM.cpp" "${CRYPTOLENS_ROOT}/src/cryptolens_internals.cpp" "${CRYPTOLENS_ROOT}/third_party/base64_OpenBSD/base64.cpp")
set (CRYPTOLENS_LIBS ${CRYPTOLENS_LIBS} "pthread" "dl")
set (CRYPTOLENS_PRIVATE_INCLUDE_DIRS ${CRYPTOLENS_PRIVATE_INCLUDE_DIRS} "${CRYPTOLENS_ROOT}/include/cryptolens")
set (CRYPTOLENS_PUBLIC_INCLUDE_DIRS ${CRYPTOLENS_PUBLIC_INCLUDE_DIRS} "${CRYPTOLENS_ROOT}/include")

if (${OPENSSL_FOUND})
  set (CRYPTOLENS_SRC  ${CRYPTOLENS_SRC} "${CRYPTOLENS_ROOT}/src/SignatureVerifier_OpenSSL.cpp")
  set (CRYPTOLENS_LIBS ${CRYPTOLENS_LIBS} ${OPENSSL_LIBRARIES})
  set (CRYPTOLENS_PRIVATE_INCLUDE_DIRS ${CRYPTOLENS_PRIVATE_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
endif ()

if (${CURL_FOUND})
  set (CRYPTOLENS_SRC ${CRYPTOLENS_SRC} "${CRYPTOLENS_ROOT}/src/RequestHandler_curl.cpp")
  set (CRYPTOLENS_LIBS ${CRYPTOLENS_LIBS} ${CURL_LIBRARIES})
  set (CRYPTOLENS_PRIVATE_INCLUDE_DIRS ${CRYPTOLENS_PRIVATE_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS})


  if ((${CRYPTOLENS_CURL_EMBED_CACERTS}) OR (${SKM_CURL_EMBED_CACERTS}))
    add_definitions (-DCRYPTOLENS_CURL_EMBED_CACERTS)
    set (SRC ${SRC} "${CRYPTOLENS_ROOT}/src/RequestHandler_curl_cacerts.cpp")
  endif ()
endif ()

add_library (cryptolens STATIC ${CRYPTOLENS_SRC})
target_link_libraries (cryptolens ${CRYPTOLENS_LIBS})
target_include_directories (cryptolens PRIVATE ${CRYPTOLENS_PRIVATE_INCLUDE_DIRS})
target_include_directories (cryptolens PUBLIC ${CRYPTOLENS_PUBLIC_INCLUDE_DIRS})
set_property (TARGET cryptolens PROPERTY CXX_STANDARD 11)
set_property (TARGET cryptolens PROPERTY CXX_STANDARD_REQURED ON)
