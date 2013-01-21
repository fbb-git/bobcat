#include "hmacbuf.ih"

HMacBuf::HMacBuf(std::string const &key, char const *type, size_t bufsize)
:
    d_pimpl(new HMacBufImp(key, bufsize))
{
    try
    {
        OpenSSL_add_all_digests();
        d_pimpl->md = EVP_get_digestbyname(type);

        if (!d_pimpl->md)
        {
            if (type == 0)
                type = "** unspecified hmac-digest type **";
    
            throw Exception(1), "HMacBuf `" << type << "' not available";
        }
        d_pimpl->buffer = new char[bufsize];
        open();
    }
    catch (...)
    {
        delete d_pimpl;
        throw;
    }
}
