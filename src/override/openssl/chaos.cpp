#include <stdio.h>
#include <stdlib.h>

#include <openssl/bn.h>
#include <openssl/rsa.h>

#include <cryptolens/tests/core.hpp>

namespace cryptolens_io {

namespace tests {

namespace override {

namespace openssl {

namespace chaos {

Chaos * chaos = nullptr;

} // namespace chaos

} // namespace openssl

} // namespace override

} // namespace tests

} // namespace cryptolens_io

extern "C" {

BIGNUM *rBN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
BIGNUM *rBN_new();
BIGNUM *rBN_secure_new();
EVP_MD_CTX *rEVP_MD_CTX_new();
EVP_PKEY *rEVP_PKEY_new();
int rEVP_PKEY_set1_RSA(EVP_PKEY *pkey, RSA *key);
int rEVP_DigestVerifyInit(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx, const EVP_MD *type, ENGINE *e, EVP_PKEY *pkey);
int rEVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt); // EVP_DigestVerifyUpdate is just defined as EVP_DigestUpdate
int rEVP_DigestVerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sig, size_t siglen);
RSA * rRSA_new(void);
int rRSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d);

BIGNUM *
BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return rBN_bin2bn(s, len, ret);
}

BIGNUM *
BN_new(void)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return rBN_new();
}

BIGNUM *
BN_secure_new(void)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return rBN_secure_new();
}

EVP_MD_CTX *
EVP_MD_CTX_new(void)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return rEVP_MD_CTX_new();
}

EVP_PKEY *
EVP_PKEY_new(void)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return rEVP_PKEY_new();
}

int
EVP_PKEY_set1_RSA(EVP_PKEY *pkey, RSA *key)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return 0;
  }

  return rEVP_PKEY_set1_RSA(pkey, key);
}

int
EVP_DigestVerifyInit(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx, const EVP_MD *type, ENGINE *e, EVP_PKEY *pkey)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return 0;
  }

  return rEVP_DigestVerifyInit(ctx, pctx, type, e, pkey);
}

int
EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return 0;
  }

  return rEVP_DigestUpdate(ctx, d, cnt);
}

int
EVP_DigestVerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sig, size_t siglen)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return 0;
  }

  return rEVP_DigestVerifyFinal(ctx, sig, siglen);
}

RSA *
RSA_new(void)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return NULL;
  }

  return rRSA_new();
}

int
RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d)
{
  if (cryptolens_io::tests::override::openssl::chaos::chaos->should_fail()) {
    return 0;
  }

  return rRSA_set0_key(r, n, e, d);
}

} // extern "C"
