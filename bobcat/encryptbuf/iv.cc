#include "encryptbuf.ih"

std::string const &EncryptBuf::iv() const
{
    return d_pimpl->iv;
}
