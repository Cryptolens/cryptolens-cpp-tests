#include <iostream>

#include <openssl/evp.h>

int
EVP_DigestVerifyInit(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx, const EVP_MD *type, ENGINE *e, EVP_PKEY *pkey)
{
  return 1;
}

int
EVP_DigestVerifyUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt)
{
  char const* p = (char const*)d;
  int acc = 0;
  for (size_t i = 0; i < cnt; ++i) {
    acc ^= (int)p[i];
  }

  std::cout << acc << std::endl;

  return 1;
}

int
EVP_DigestVerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sig, size_t siglen)
{
  int acc = 0;
  for (size_t i = 0; i < siglen; ++i) {
    acc ^= (int)sig[i];
  }

  std::cout << acc << std::endl;

  return 1;
}
