#pragma once

#include <curl/curl.h>

#include <cryptolens/core.hpp>
#include <cryptolens/Error.hpp>
#include <cryptolens/Configuration_Unix.hpp>
#include <cryptolens/MachineCodeComputer_static.hpp>


namespace tests_v20180502 {

namespace cryptolens = ::cryptolens_io::v20180502;
using Cryptolens = cryptolens::basic_SKM<cryptolens::RequestHandler_curl, cryptolens::SignatureVerifier_OpenSSL>;

} // namespace tests_v20180502

namespace tests_v20190401 {

namespace cryptolens = ::cryptolens_io::v20190401;
using Cryptolens = cryptolens::basic_Cryptolens<cryptolens::Configuration_Unix<cryptolens::MachineCodeComputer_static>>;
using Cryptolens_IgnoreExpires = cryptolens::basic_Cryptolens<cryptolens::Configuration_Unix_IgnoreExpires<cryptolens::MachineCodeComputer_static>>;

} // namespace tests_v20190401 
