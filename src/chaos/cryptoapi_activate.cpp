///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <random>

#include <cryptolens/core.hpp>
#include <cryptolens/Error.hpp>
#include <cryptolens/Configuration_Windows.hpp>
#include <cryptolens/MachineCodeComputer_static.hpp>

#include <cryptolens/tests/core.hpp>
///////////////////////////////////////////////////////////////////////////////

#include <Windows.h>

#define WINADVAPI
#define WINAPI
#include <wincrypt.h>





typedef
WINADVAPI
BOOL
(WINAPI *pCryptCreateHash)(
    _In_    HCRYPTPROV  hProv,
    _In_    ALG_ID      Algid,
    _In_    HCRYPTKEY   hKey,
    _In_    DWORD       dwFlags,
    _Out_   HCRYPTHASH  *phHash
    );

typedef
WINADVAPI
BOOL
(WINAPI *pCryptHashData)(
    _In_                    HCRYPTHASH  hHash,
    _In_reads_bytes_(dwDataLen)  CONST BYTE  *pbData,
    _In_                    DWORD   dwDataLen,
    _In_                    DWORD   dwFlags
    );

typedef
WINADVAPI
BOOL
(WINAPI *pCryptVerifySignatureA)(
    _In_                    HCRYPTHASH  hHash,
    _In_reads_bytes_(dwSigLen)   CONST BYTE  *pbSignature,
    _In_                    DWORD       dwSigLen,
    _In_                    HCRYPTKEY   hPubKey,
    _In_opt_                LPCSTR    szDescription,
    _In_                    DWORD       dwFlags
    );

typedef
WINADVAPI
BOOL
(WINAPI *pCryptVerifySignatureW)(
    _In_                    HCRYPTHASH  hHash,
    _In_reads_bytes_(dwSigLen)   CONST BYTE  *pbSignature,
    _In_                    DWORD       dwSigLen,
    _In_                    HCRYPTKEY   hPubKey,
    _In_opt_                LPCWSTR    szDescription,
    _In_                    DWORD       dwFlags
    );

typedef
WINADVAPI
BOOL
(WINAPI *pCryptAcquireContextA)(
    _Out_       HCRYPTPROV  *phProv,
    _In_opt_    LPCSTR    szContainer,
    _In_opt_    LPCSTR    szProvider,
    _In_        DWORD       dwProvType,
    _In_        DWORD       dwFlags
    );

typedef
WINADVAPI
BOOL
(WINAPI *pCryptAcquireContextW)(
    _Out_       HCRYPTPROV  *phProv,
    _In_opt_    LPCWSTR    szContainer,
    _In_opt_    LPCWSTR    szProvider,
    _In_        DWORD       dwProvType,
    _In_        DWORD       dwFlags
    );

typedef
WINADVAPI
BOOL
(WINAPI *pCryptImportKey)(
    _In_                    HCRYPTPROV  hProv,
    _In_reads_bytes_(dwDataLen)  CONST BYTE  *pbData,
    _In_                    DWORD       dwDataLen,
    _In_                    HCRYPTKEY   hPubKey,
    _In_                    DWORD       dwFlags,
    _Out_                   HCRYPTKEY   *phKey
    );

typedef
WINADVAPI
BOOL
(WINAPI *pCryptDestroyKey)(
    _In_    HCRYPTKEY   hKey
    );

typedef
WINADVAPI
BOOL
(WINAPI* pCryptDestroyHash)(
	_In_    HCRYPTHASH   hKey
	);

typedef
WINADVAPI
BOOL
(WINAPI *pCryptReleaseContext)(
    _In_    HCRYPTPROV  hProv,
    _In_    DWORD       dwFlags
    );

HMODULE advapi32 = LoadLibrary("Advapi32.dll");

WINADVAPI
BOOL
WINAPI
CryptCreateHash(
    _In_    HCRYPTPROV  hProv,
    _In_    ALG_ID      Algid,
    _In_    HCRYPTKEY   hKey,
    _In_    DWORD       dwFlags,
    _Out_   HCRYPTHASH  *phHash
    )
{
	if (cryptolens_io::tests::override::cryptoapi::chaos::chaos->should_fail()) {
		return FALSE;
	}

    auto m = (pCryptCreateHash)GetProcAddress(advapi32, "CryptCreateHash");

    return m(hProv, Algid, hKey, dwFlags, phHash);
}

WINADVAPI
BOOL
WINAPI
CryptHashData(
    _In_                    HCRYPTHASH  hHash,
    _In_reads_bytes_(dwDataLen)  CONST BYTE  *pbData,
    _In_                    DWORD   dwDataLen,
    _In_                    DWORD   dwFlags
    )
{
	if (cryptolens_io::tests::override::cryptoapi::chaos::chaos->should_fail()) {
		return FALSE;
	}

    auto m = (pCryptHashData)GetProcAddress(advapi32, "CryptHashData");

    return m(hHash, pbData, dwDataLen, dwFlags);
}

WINADVAPI
BOOL
WINAPI
CryptVerifySignatureA(
    _In_                    HCRYPTHASH  hHash,
    _In_reads_bytes_(dwSigLen)   CONST BYTE  *pbSignature,
    _In_                    DWORD       dwSigLen,
    _In_                    HCRYPTKEY   hPubKey,
    _In_opt_                LPCSTR    szDescription,
    _In_                    DWORD       dwFlags
    )
{
	if (cryptolens_io::tests::override::cryptoapi::chaos::chaos->should_fail()) {
		return FALSE;
	}

    auto m = (pCryptVerifySignatureA)GetProcAddress(advapi32, "CryptVerifySignatureA");

    return m(hHash, pbSignature, dwSigLen, hPubKey, szDescription, dwFlags);
}
WINADVAPI
BOOL
WINAPI
CryptVerifySignatureW(
    _In_                    HCRYPTHASH  hHash,
    _In_reads_bytes_(dwSigLen)   CONST BYTE  *pbSignature,
    _In_                    DWORD       dwSigLen,
    _In_                    HCRYPTKEY   hPubKey,
    _In_opt_                LPCWSTR    szDescription,
    _In_                    DWORD       dwFlags
    )
{
	if (cryptolens_io::tests::override::cryptoapi::chaos::chaos->should_fail()) {
		return FALSE;
	}

    auto m = (pCryptVerifySignatureW)GetProcAddress(advapi32, "CryptVerifySignatureW");

    return m(hHash, pbSignature, dwSigLen, hPubKey, szDescription, dwFlags);
}

WINADVAPI
BOOL
WINAPI
CryptAcquireContextA(
    _Out_       HCRYPTPROV  *phProv,
    _In_opt_    LPCSTR    szContainer,
    _In_opt_    LPCSTR    szProvider,
    _In_        DWORD       dwProvType,
    _In_        DWORD       dwFlags
    )
{
	if (cryptolens_io::tests::override::cryptoapi::chaos::chaos->should_fail()) {
		return FALSE;
	}

    auto m = (pCryptAcquireContextA)GetProcAddress(advapi32, "CryptAcquireContextA");

    return m(phProv, szContainer, szProvider, dwProvType, dwFlags);
}
WINADVAPI
BOOL
WINAPI
CryptAcquireContextW(
    _Out_       HCRYPTPROV  *phProv,
    _In_opt_    LPCWSTR    szContainer,
    _In_opt_    LPCWSTR    szProvider,
    _In_        DWORD       dwProvType,
    _In_        DWORD       dwFlags
    )
{
	if (cryptolens_io::tests::override::cryptoapi::chaos::chaos->should_fail()) {
		return FALSE;
	}

    auto m = (pCryptAcquireContextW)GetProcAddress(advapi32, "CryptAcquireContextW");

    return m(phProv, szContainer, szProvider, dwProvType, dwFlags);
}

WINADVAPI
BOOL
WINAPI
CryptImportKey(
    _In_                    HCRYPTPROV  hProv,
    _In_reads_bytes_(dwDataLen)  CONST BYTE  *pbData,
    _In_                    DWORD       dwDataLen,
    _In_                    HCRYPTKEY   hPubKey,
    _In_                    DWORD       dwFlags,
    _Out_                   HCRYPTKEY   *phKey
    )
{
	if (cryptolens_io::tests::override::cryptoapi::chaos::chaos->should_fail()) {
		return FALSE;
	}

    auto m = (pCryptImportKey)GetProcAddress(advapi32, "CryptImportKey");

    return m(hProv, pbData, dwDataLen, hPubKey, dwFlags, phKey);
}

WINADVAPI
BOOL
WINAPI
CryptDestroyKey(
    _In_    HCRYPTKEY   hKey
    )
{
    auto m = (pCryptDestroyKey)GetProcAddress(advapi32, "CryptDestroyKey");

    return m(hKey);
}

WINADVAPI
BOOL
WINAPI
CryptDestroyHash(
	_In_    HCRYPTHASH   hKey
)
{
	auto m = (pCryptDestroyHash)GetProcAddress(advapi32, "CryptDestroyHash");

	return m(hKey);
}
WINADVAPI
BOOL
WINAPI
CryptReleaseContext(
    _In_    HCRYPTPROV  hProv,
    _In_    DWORD       dwFlags
    )
{
    auto m = (pCryptReleaseContext)GetProcAddress(advapi32, "CryptReleaseContext");

    return m(hProv, dwFlags);
}


///////////////////////////////////////////////////////////////////////////////

namespace cryptolens_io { namespace tests { namespace override { namespace cryptoapi { namespace chaos {
    Chaos* chaos = nullptr;
}}}}} // namespace cryptolens_io::tests::override::cryptoapi::chaos

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
	cryptolens_io::tests::override::cryptoapi::chaos::chaos = &chaos;

	std::default_random_engine g;
	cryptolens_io::tests::seed_generator(g);
	std::uniform_real_distribution<double> d(0.0, 1.0);

	for (size_t ITER = 0; ITER < 1000; ++ITER) {
		chaos.set_failure_probability(d(g));

		cryptolens::Error e;
		Cryptolens cryptolens_handle(e);
		// Setting up the signature verifier with credentials from "Security Settings"
		// on cryptolens.io
		if (d(g) > 0.5) {
			cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
			cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
		}
		else {
			cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
			cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
		}
		cryptolens_handle.machine_code_computer.set_machine_code(e, "289jf2afs3");

		// Reply from Cryptolens Web API
		std::string cryptolens_reply("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjM2NDYsIklEIjo0LCJLZXkiOiJNUERXWS1QUUFPVy1GS1NDSC1TR0FBVSIsIkNyZWF0ZWQiOjE0OTAzMTM2MDAsIkV4cGlyZXMiOjE0OTI5MDU2MDAsIlBlcmlvZCI6MzAsIkYxIjpmYWxzZSwiRjIiOmZhbHNlLCJGMyI6ZmFsc2UsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6ZmFsc2UsIkY3IjpmYWxzZSwiRjgiOmZhbHNlLCJOb3RlcyI6bnVsbCwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6MzE4NzYsIkN1c3RvbWVyIjpudWxsLCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiIiwiSVAiOiIxNTUuNC4xMzQuMjciLCJUaW1lIjoxNDkxODk4OTE4fSx7Ik1pZCI6ImxvbCIsIklQIjoiMTU1LjQuMTM0LjI3IiwiVGltZSI6MTQ5MTg5ODk5NX0seyJNaWQiOiIyODlqZjJhZnNmIiwiSVAiOiIxNTUuNC4xMzQuMjciLCJUaW1lIjoxNDkxOTAwNTQ2fSx7Ik1pZCI6IjI4OWpmMmFmczMiLCJJUCI6IjE1NS40LjEzNC4yNyIsIlRpbWUiOjE0OTE5MDA2MzZ9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoxMCwiQWxsb3dlZE1hY2hpbmVzIjoiIiwiRGF0YU9iamVjdHMiOltdLCJTaWduRGF0ZSI6MTQ5NTAxOTc2Nn0=\",\"signature\":\"SqPm8dtTdVBrXrmJzXer7qq6dvdQfctJxP8mar+RO9p8QABsgWWaX+uH7aOGMBd42eg+2Omorv7Ks6V7itRhXPeeq5qWoKuefd+pTsFagvqiu2N/E2Np8fpt51aqmiygdHLECo42nJwVD8JzlN67hnvJTgY7iyDWhG7qFK9Slk+kEJjjK/0J1pJYI6nOi+7sgBV7ZRca+7DmiP6OmOjNfySps6PdiB7QbiSis5f24Xmc5OYyRe3fzZmAueqF3eymBK19XhYFroWXeT4tcNsBNJsv+YfItovGbJysLx+K4ppltd2GNwEFQgtE3ILGOUj7EVbeQmQXg9m2c5MTPyk8iA==\",\"result\":0,\"message\":\"\"}");

		cryptolens::optional<cryptolens::LicenseKey> license_key = cryptolens_handle.make_license_key(e, cryptolens_reply);

		// Check if request was successful and signature is valid
		if (!license_key) {
			std::cout << "Failed to construct license key!" << std::endl;
		}
		else {
			std::cout << "License key for product with id: " << license_key->get_product_id() << std::endl;
		}
	}
}
