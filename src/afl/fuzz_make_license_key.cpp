#include <iostream>
#include <sstream>

#include <curl/curl.h>

#include <cryptolens/tests/core.hpp>
#include <cryptolens/tests/Configuration_fuzz.hpp>

#include <cryptolens/core.hpp>
#include <cryptolens/Error.hpp>

namespace cryptolens = ::cryptolens_io::v20190401;
using Cryptolens = cryptolens::basic_Cryptolens<Configuration_fuzz>;

int main()
{
    curl_global_init(CURL_GLOBAL_SSL);
#if 1 && defined(__AFL_HAVE_MANUAL_CONTROL)
  __AFL_INIT();

  while(__AFL_LOOP(1000))
#else
  for (int i = 0; i < 1; ++i)
#endif
  {
    // Read inputs from stdin
    auto inputs = cryptolens_io::tests::read_inputs();
    if (inputs.size() != 4) { break; }

    std::string modulus = std::move(inputs.front()); inputs.pop_front();

    std::string exponent = std::move(inputs.front()); inputs.pop_front();

    std::string machine_code = std::move(inputs.front()); inputs.pop_front();

    std::string cryptolens_reply = std::move(inputs.front()); inputs.pop_front();

    // Run program

    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, modulus);
    cryptolens_handle.signature_verifier.set_exponent_base64(e, exponent);
    cryptolens_handle.machine_code_computer.set_machine_code(e, machine_code);

    cryptolens::optional<cryptolens::LicenseKey> license_key = cryptolens_handle.make_license_key(e, cryptolens_reply);

    if (e) {
      std::cout << "Error: " << e.get_subsystem() << " " << e.get_reason() << " " << e.get_extra() << std::endl;

      break;
    }

    cryptolens_io::tests::touch_license_key(license_key);
  }

  curl_global_cleanup();
}
