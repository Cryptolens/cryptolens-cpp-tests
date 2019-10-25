#include <iostream>

#include <Windows.h>
#define _WINHTTP_INTERNAL_
#include <winhttp.h>


#include <wincrypt.h>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <random>

#include <cryptolens/core.hpp>
#include <cryptolens/Error.hpp>
#include <cryptolens/Configuration_Windows.hpp>
#include <cryptolens/MachineCodeComputer_static.hpp>

#include <cryptolens/tests/core.hpp>

namespace cryptolens = ::cryptolens_io::v20190401;
using Cryptolens = cryptolens::basic_Cryptolens<cryptolens::Configuration_Windows<cryptolens::MachineCodeComputer_static>>;

/*
 * This example assumes the reply from the web server has fetched in some
 * other fasion, and then verifies the signature and finally checks
 * some properties on the license key.
 */
int main()
{
  cryptolens_io::tests::RandomChaos chaos(0.0);
  cryptolens_io::tests::override::winhttp::chaos::chaos = &chaos;

  std::default_random_engine g;
  cryptolens_io::tests::seed_generator(g);
  std::uniform_real_distribution<double> d(0.0,1.0);

  for (size_t ITER = 0; ITER < 1000; ++ITER) {
    chaos.set_failure_probability(d(g));

    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    // Setting up the signature verifier with credentials from "Security Settings"
    // on cryptolens.io
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "289jf2afs3");

    cryptolens::optional<cryptolens::LicenseKey> license_key =
      cryptolens_handle.activate
        ( // Object used for reporting if an error occured
          e
        , // Cryptolens Access Token
          "WyI0NjUiLCJBWTBGTlQwZm9WV0FyVnZzMEV1Mm9LOHJmRDZ1SjF0Vk52WTU0VzB2Il0="
        , // Product id
          3646
        , // License Key
          "MPDWY-PQAOW-FKSCH-SGAAU"
        );

    std::string message = cryptolens_handle.last_message(e, "WyIxNzk0IiwiUkhSTWl3ekVBYTRlNjZFQUtVRUNObzBNWDAvZnRmQ2tKUGVkQWZJcSJd", "stable", 1234);

    if (e) {
      // Error occured trying to activate the license key
      using namespace cryptolens::errors;

      if (e.get_subsystem() == Subsystem::Main) {
        // Handle errors from the Cryptolens API
        std::cout << "Cryptolens error: " << e.get_reason() << std::endl;
      } else {
        std::cout << "Unhandled error: " << e.get_subsystem() << " " << e.get_reason() << " " << e.get_extra() << std::endl;
      }
      continue;
    }

    std::cout << "MOTD: " << message << std::endl;
    std::cout << "License key for product with id: " << license_key->get_product_id() << std::endl;

    // Use LicenseKeyChecker to check properties of the license key
    if (license_key->check().has_expired(1234567)) {
      std::cout << "Your subscription has expired." << std::endl;
      continue;
    }

    if (license_key->check().has_feature(1)) { std::cout << "Welcome! Pro version enabled!" << std::endl; }
  }
}


///////////////////////////////////////////////////////////////////////////////

namespace cryptolens_io { namespace tests { namespace override { namespace winhttp { namespace chaos {

Chaos * chaos = nullptr;

}}}}} // namespace cryptolens_io::tests::override::curl::chaos

typedef
WINHTTPAPI
HINTERNET
(WINAPI *pWinHttpOpen)
(
	_In_opt_z_ LPCWSTR pszAgentW,
	_In_ DWORD dwAccessType,
	_In_opt_z_ LPCWSTR pszProxyW,
	_In_opt_z_ LPCWSTR pszProxyBypassW,
	_In_ DWORD dwFlags
);

typedef
WINHTTPAPI
HINTERNET
(WINAPI *pWinHttpConnect)
(
    IN HINTERNET hSession,
    IN LPCWSTR pswzServerName,
    IN INTERNET_PORT nServerPort,
    IN DWORD dwReserved
);

typedef
WINHTTPAPI
HINTERNET
(WINAPI *pWinHttpOpenRequest)
(
    IN HINTERNET hConnect,
    IN LPCWSTR pwszVerb,
    IN LPCWSTR pwszObjectName,
    IN LPCWSTR pwszVersion,
    IN LPCWSTR pwszReferrer OPTIONAL,
    IN LPCWSTR FAR * ppwszAcceptTypes OPTIONAL,
    IN DWORD dwFlags
);

typedef
BOOL
(__stdcall *pWinHttpSendRequest)
(
    IN HINTERNET hRequest,
    _In_reads_opt_(dwHeadersLength) LPCWSTR lpszHeaders,
    IN DWORD dwHeadersLength,
    _In_reads_bytes_opt_(dwOptionalLength) LPVOID lpOptional,
    IN DWORD dwOptionalLength,
    IN DWORD dwTotalLength,
    IN DWORD_PTR dwContext
);

typedef
WINHTTPAPI
BOOL
(WINAPI *pWinHttpReceiveResponse)
(
    IN HINTERNET hRequest,
    IN LPVOID lpReserved
);

typedef
BOOL
(__stdcall *pWinHttpQueryDataAvailable)
(
    IN HINTERNET hRequest,
    __out_data_source(NETWORK) LPDWORD lpdwNumberOfBytesAvailable
);

typedef
BOOL
(__stdcall *pWinHttpReadData)
(
    IN HINTERNET hRequest,
    _Out_writes_bytes_to_(dwNumberOfBytesToRead, *lpdwNumberOfBytesRead) __out_data_source(NETWORK) LPVOID lpBuffer,
    IN DWORD dwNumberOfBytesToRead,
    OUT LPDWORD lpdwNumberOfBytesRead
);

typedef
BOOL
(__stdcall *pWinHttpCloseHandle)
(
	IN HINTERNET hInternet
);

HMODULE winhttp = LoadLibrary("Winhttp.dll");

WINHTTPAPI
HINTERNET
WINAPI
WinHttpOpen
(
    _In_opt_z_ LPCWSTR pszAgentW,
    _In_ DWORD dwAccessType,
    _In_opt_z_ LPCWSTR pszProxyW,
    _In_opt_z_ LPCWSTR pszProxyBypassW,
    _In_ DWORD dwFlags
)
{
    if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
      return NULL;
    }

    auto m = (pWinHttpOpen)GetProcAddress(winhttp, "WinHttpOpen");

    return m(pszAgentW, dwAccessType, pszProxyW, pszProxyBypassW, dwFlags);
}

WINHTTPAPI
HINTERNET
WINAPI
WinHttpConnect
(
    IN HINTERNET hSession,
    IN LPCWSTR pswzServerName,
    IN INTERNET_PORT nServerPort,
    IN DWORD dwReserved
)
{
    if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
      return NULL;
    }

    auto m = (pWinHttpConnect)GetProcAddress(winhttp, "WinHttpConnect");

    return m(hSession, pswzServerName, nServerPort, dwReserved);
}

WINHTTPAPI
HINTERNET
WINAPI
WinHttpOpenRequest
(
    IN HINTERNET hConnect,
    IN LPCWSTR pwszVerb,
    IN LPCWSTR pwszObjectName,
    IN LPCWSTR pwszVersion,
    IN LPCWSTR pwszReferrer OPTIONAL,
    IN LPCWSTR FAR * ppwszAcceptTypes OPTIONAL,
    IN DWORD dwFlags
)
{
    if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
      return NULL;
    }

    auto m = (pWinHttpOpenRequest)GetProcAddress(winhttp, "WinHttpOpenRequest");

    return m(hConnect, pwszVerb, pwszObjectName, pwszVersion, pwszReferrer, ppwszAcceptTypes, dwFlags);
}

BOOLAPI
WinHttpSendRequest
(
    IN HINTERNET hRequest,
    _In_reads_opt_(dwHeadersLength) LPCWSTR lpszHeaders,
    IN DWORD dwHeadersLength,
    _In_reads_bytes_opt_(dwOptionalLength) LPVOID lpOptional,
    IN DWORD dwOptionalLength,
    IN DWORD dwTotalLength,
    IN DWORD_PTR dwContext
)
{
    if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
      return FALSE;
    }

    auto m = (pWinHttpSendRequest)GetProcAddress(winhttp, "WinHttpSendRequest");

    return m(hRequest, lpszHeaders, dwHeadersLength, lpOptional, dwOptionalLength, dwTotalLength, dwContext);
}

WINHTTPAPI
BOOL
WINAPI
WinHttpReceiveResponse
(
    IN HINTERNET hRequest,
    IN LPVOID lpReserved
)
{
    if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
      return FALSE;
    }

    auto m = (pWinHttpReceiveResponse)GetProcAddress(winhttp, "WinHttpReceiveResponse");

    return m(hRequest, lpReserved);
}

BOOLAPI
WinHttpQueryDataAvailable
(
    IN HINTERNET hRequest,
    __out_data_source(NETWORK) LPDWORD lpdwNumberOfBytesAvailable
)
{
    if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
      return FALSE;
    }

    auto m = (pWinHttpQueryDataAvailable)GetProcAddress(winhttp, "WinHttpQueryDataAvailable");

    return m(hRequest, lpdwNumberOfBytesAvailable);
}

BOOLAPI
WinHttpReadData
(
    IN HINTERNET hRequest,
    _Out_writes_bytes_to_(dwNumberOfBytesToRead, *lpdwNumberOfBytesRead) __out_data_source(NETWORK) LPVOID lpBuffer,
    IN DWORD dwNumberOfBytesToRead,
    OUT LPDWORD lpdwNumberOfBytesRead
)
{
    if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
      return FALSE;
    }

    auto m = (pWinHttpReadData)GetProcAddress(winhttp, "WinHttpReadData");

    return m(hRequest, lpBuffer, dwNumberOfBytesToRead, lpdwNumberOfBytesRead);
}

BOOLAPI
WinHttpCloseHandle
(
	IN HINTERNET hInternet
)
{
	//if (cryptolens_io::tests::override::winhttp::chaos::chaos->should_fail()) {
	//	return FALSE;
	//}

	auto m = (pWinHttpCloseHandle)GetProcAddress(winhttp, "WinHttpCloseHandle");

	return m(hInternet);
}