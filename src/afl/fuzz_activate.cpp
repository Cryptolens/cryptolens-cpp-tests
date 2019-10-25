#include <iostream>
#include <sstream>

#include <curl/curl.h>

#include <cryptolens/tests/core.hpp>
#include <cryptolens/tests/Configuration_fuzz.hpp>
#include <cryptolens/tests/override/curl/inputs.hpp>

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
    if (inputs.size() < 6) { break; }

    std::string modulus = std::move(inputs.front()); inputs.pop_front();

    std::string exponent = std::move(inputs.front()); inputs.pop_front();

    std::string machine_code = std::move(inputs.front()); inputs.pop_front();

    std::string access_token = std::move(inputs.front()); inputs.pop_front();

    std::string product_id_ = std::move(inputs.front()); inputs.pop_front();
    std::istringstream product_id__(product_id_); int product_id;
    if (!(product_id__ >> product_id)) { break; }

    std::string key_string = std::move(inputs.front()); inputs.pop_front();

    cryptolens_io::tests::override::curl::inputs::inputs = std::move(inputs);

    // Run program

    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, modulus);
    cryptolens_handle.signature_verifier.set_exponent_base64(e, exponent);
    cryptolens_handle.machine_code_computer.set_machine_code(e, machine_code);

    cryptolens::optional<cryptolens::LicenseKey> license_key =
      cryptolens_handle.activate(e, access_token, product_id, key_string);

    if (e) {
      // Error occured trying to activate the license key
      using namespace cryptolens::errors;

      if (e.get_subsystem() == Subsystem::Main) {
        // Handle errors from the Cryptolens API
        std::cout << "Cryptolens error: " << e.get_reason() << std::endl;
      } else if (e.get_subsystem() == Subsystem::RequestHandler && e.get_reason() == RequestHandler_curl::PERFORM) {
        int curlcode = e.get_extra();
        std::cout << "Error connecting to the server: curlcode: " << curlcode << std::endl;
      } else {
        std::cout << "Unhandled error: " << e.get_subsystem() << " " << e.get_reason() << " " << e.get_extra() << std::endl;
      }
      break;
    }

    cryptolens_io::tests::touch_license_key(license_key);
  }

  curl_global_cleanup();
}
