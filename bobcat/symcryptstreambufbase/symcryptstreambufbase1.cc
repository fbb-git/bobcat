#include "symcryptstreambufbase.ih"

SymCryptStreambufBase::SymCryptStreambufBase(
            int (*evpInit_ex)(EVP_CIPHER_CTX *, EVP_CIPHER const *,
                ENGINE *, unsigned char const *key, unsigned char const *iv),

            int (*evpUpdate)(EVP_CIPHER_CTX *, 
                unsigned char *out, int *outl, 
                unsigned char const *in, int inl),

            int (*evpFinal_ex)(EVP_CIPHER_CTX *, 
                unsigned char *out, int *outl), 

            std::istream &in, char const *type,
            std::string const &keyParam, std::string const &ivParam, 
            size_t bufSize, size_t filterBufSize, ENGINE *engine
)
:
    IFilterStreambuf(filterBufSize),
    d_ctx(EVP_CIPHER_CTX_new()),
    d_inBufSize(bufSize < 100 ? 100 : bufSize),
    d_in(in),
    d_evpUpdate(evpUpdate),
    d_evpFinal_ex(evpFinal_ex),
    d_inBuf(new char[d_inBufSize])
{
    OpenSSL_add_all_ciphers();

    EVP_CIPHER const *cipherType = 0;

    if (type)
        cipherType = EVP_get_cipherbyname(type);

    if (cipherType == 0)
        throw Exception() << "FBB::ISymCryptStreambuf: cipher " <<
            (type ? type : "0") << " not available";

    string key(keyParam);
    key.resize(EVP_MAX_KEY_LENGTH);

    string iv(ivParam);
    iv.resize(EVP_MAX_IV_LENGTH);

    (*evpInit_ex)(d_ctx, cipherType, engine, 
                reinterpret_cast<unsigned char const *>(key.data()),
                reinterpret_cast<unsigned char const *>(iv.data()));

    d_blockSize = EVP_CIPHER_CTX_block_size(d_ctx);
}



