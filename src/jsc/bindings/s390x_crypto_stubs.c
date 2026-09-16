// Stubs for OpenSSL functions not available in BoringSSL
// These are referenced by Bun's crypto code but BoringSSL doesn't
// implement them. Return NULL to signal "not supported".

#include <stddef.h>

// Blowfish ciphers - not in BoringSSL
void* EVP_bf_cbc(void) { return NULL; }
void* EVP_bf_cfb(void) { return NULL; }
void* EVP_bf_ecb(void) { return NULL; }

// AES CFB128 - not in BoringSSL
void* EVP_aes_128_cfb128(void) { return NULL; }
void* EVP_aes_256_cfb128(void) { return NULL; }

// Cipher/MD enumeration - not in BoringSSL
void EVP_CIPHER_do_all_sorted(void (*fn)(void*, void*, void*, void*), void* arg) { (void)fn; (void)arg; }
void EVP_MD_do_all_sorted(void (*fn)(void*, void*, void*, void*), void* arg) { (void)fn; (void)arg; }

// EVP_MAC API - not in BoringSSL
void* EVP_MAC_fetch(void* ctx, const char* algorithm, const char* properties) { (void)ctx; (void)algorithm; (void)properties; return NULL; }
void* EVP_MAC_CTX_new(void* mac) { (void)mac; return NULL; }
void EVP_MAC_CTX_free(void* ctx) { (void)ctx; }
void EVP_MAC_free(void* mac) { (void)mac; }
int EVP_MAC_init(void* ctx, const unsigned char* key, size_t keylen, void* params) { (void)ctx; (void)key; (void)keylen; (void)params; return 0; }
int EVP_MAC_update(void* ctx, const unsigned char* data, size_t datalen) { (void)ctx; (void)data; (void)datalen; return 0; }
int EVP_MAC_final(void* ctx, unsigned char* out, size_t* outl, size_t outsize) { (void)ctx; (void)out; (void)outl; (void)outsize; return 0; }
