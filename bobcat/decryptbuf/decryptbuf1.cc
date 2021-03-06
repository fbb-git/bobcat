#include "decryptbuf.ih"

DecryptBuf::DecryptBuf(ostream &outStream, char const *type, 
                        string key, string iv, size_t bufsize)
:
    d_pimpl(new DecryptBufImp(outStream, bufsize))
{
    try
    {
        OpenSSL_add_all_ciphers();
    
        d_pimpl->md = EVP_get_cipherbyname(type);
        if (!d_pimpl->md)
        {
            if (type == 0)
                type = "** unspecified cipher type **";
    
            throw Exception{1} << "DecryptBuf `" << type << "' not available";
        }

        size_t keyLength = key.length();
        if (keyLength > EVP_MAX_KEY_LENGTH)
            keyLength = EVP_MAX_KEY_LENGTH;

        key.resize(EVP_MAX_KEY_LENGTH);
        iv.resize(EVP_MAX_IV_LENGTH);

        if
        (
            not EVP_DecryptInit_ex(d_pimpl->ctx, d_pimpl->md , 0,
                (unsigned char const *)key.data(), 
                reinterpret_cast<unsigned char const *>(iv.data()))
        )
            throw Exception{1} << "DecryptBuf: initialization failed";

        d_pimpl->buffer = new char[bufsize];
        d_pimpl->out = new char[
            bufsize + EVP_CIPHER_CTX_block_size(d_pimpl->ctx)];

        open();
    }
    catch (...)
    {
        delete d_pimpl;
        throw;
    }
}

