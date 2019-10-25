#pragma once

#include <string>

#include <cryptolens/basic_Error.hpp>

class SignatureVerifier_AlwaysAccept
{
public:
  SignatureVerifier_AlwaysAccept(::cryptolens_io::v20190401::basic_Error & e) {}

  void set_modulus_base64(::cryptolens_io::v20190401::basic_Error & e, std::string const& modulus_base64) {}
  void set_exponent_base64(::cryptolens_io::v20190401::basic_Error & e, std::string const& exponent_base64) {}

  bool verify_message(::cryptolens_io::v20190401::basic_Error & e, std::string const& message, std::string const& signature_base64) const { return true; }
};
