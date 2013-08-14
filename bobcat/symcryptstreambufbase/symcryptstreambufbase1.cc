#include "symcryptstreambufbase.ih"

SymCryptStreambufBase::SymCryptStreambufBase(
            int (*evpInit_ex)(EVP_CIPHER_CTX *, EVP_CIPHER const *,
                ENGINE *, unsigned char const *key, unsigned char const *iv),

            int (*evpUpdate)(EVP_CIPHER_CTX *, 
                unsigned char *out, int *outl, 
                unsigned char const *in, int inl),

            int (*evpFinal_ex)(EVP_CIPHER_CTX *, 
                unsigned char *out, int *outl), 

            std::istream &in, EVP_CIPHER const *type,
            size_t bufSize, std::string const &keyParam, 
            std::string const &ivParam, ENGINE *engine
)
:
    d_inBufSize(bufSize < 8 ? 8 : bufSize),
    d_in(in),
    d_evpUpdate(evpUpdate),
    d_evpFinal_ex(evpFinal_ex),
    d_inBuf(new char[d_inBufSize])
{
    string key(keyParam);
    key.resize(EVP_MAX_KEY_LENGTH);

    string iv(ivParam);
    iv.resize(EVP_MAX_IV_LENGTH);

    EVP_CIPHER_CTX_init(&d_ctx);

    (*evpInit_ex)(&d_ctx, type, engine, 
                reinterpret_cast<unsigned char const *>(key.data()),
                reinterpret_cast<unsigned char const *>(iv.data()));

    d_blockSize = EVP_CIPHER_CTX_block_size(&d_ctx);
}



