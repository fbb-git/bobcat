#include "encryptbuf.hh"

std::string const &EncryptBuf::iv() const
{
    return d_pimpl->iv;
}
