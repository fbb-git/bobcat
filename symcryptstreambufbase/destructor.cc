#include "symcryptstreambufbase.ih"

SymCryptStreambufBase::~SymCryptStreambufBase()
{
    EVP_CIPHER_CTX_free(d_ctx);
}
