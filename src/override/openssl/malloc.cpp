#include <stdlib.h>

#include "imports/openssl/bn.h"
#include "imports/openssl/evp.h"
#include "imports/openssl/rsa.h"

BIGNUM *
BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret)
{
  return (BIGNUM *)malloc(1);
}

void
BN_clear_free(BIGNUM *a)
{
  free(a);
}

void
BN_free(BIGNUM *a)
{
  free(a);
}

BIGNUM *
BN_new(void)
{
  return (BIGNUM *)malloc(1);
}

BIGNUM *
BN_secure_new(void)
{
  return (BIGNUM *)malloc(1);
}

EVP_MD_CTX *
EVP_MD_CTX_create()
{
  return (EVP_MD_CTX *)malloc(1);  
}

void
EVP_MD_CTX_destroy(EVP_MD_CTX *ctx)
{
  free(ctx);
}


EVP_PKEY *
EVP_PKEY_new()
{
  return (EVP_PKEY *)malloc(1);  
}

void
EVP_PKEY_free(EVP_PKEY *key)
{
  free(key);
}

void
RSA_free(RSA *rsa)
{
  free(rsa);
}

RSA *
RSA_new(void)
{
  return (RSA *)malloc(1);
}

int
RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d)
{
  free(n);
  free(e);
  free(d);

  return rand();
}
