#pragma once

#include <cryptolens/ResponseParser_ArduinoJson5.hpp>
#include <cryptolens/RequestHandler_curl.hpp>
#include "cryptolens/SignatureVerifier_OpenSSL.hpp"
#include <cryptolens/MachineCodeComputer_static.hpp>
#include <cryptolens/validators/TautologyValidator.hpp>

#include <cryptolens/tests/SignatureVerifier_AlwaysAccept.hpp>

struct Configuration_fuzz {
  using ResponseParser = ::cryptolens_io::v20190401::ResponseParser_ArduinoJson5;
  using RequestHandler = ::cryptolens_io::v20190401::RequestHandler_curl;
  using SignatureVerifier = ::cryptolens_io::v20190401::SignatureVerifier_OpenSSL;
//  using SignatureVerifier = SignatureVerifier_AlwaysAccept;
  using MachineCodeComputer = ::cryptolens_io::v20190401::MachineCodeComputer_static;

  template<typename Env>
  using ActivateValidator = cryptolens_io::v20190401::TautologyValidator_<Env>;
#if 0
  template<typename Env>
  using ActivateValidator = AndValidator_<Env, CorrectKeyValidator_<Env>
                          , AndValidator_<Env, CorrectProductValidator_<Env>
                          , AndValidator_<Env, OnValidMachineValidator_<Env>
                          ,                    NotExpiredValidator_ctime_<Env>
                          >>>;
#endif
};

