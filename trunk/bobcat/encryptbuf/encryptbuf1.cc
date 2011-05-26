#include "encryptbuf.ih"

EncryptBuf::EncryptBuf(ostream &outStream, char const *type, 
                        string key, string iv, size_t bufsize)
:
    d_pimpl(new EncryptBufImp(outStream, iv, bufsize))
{
    try
    {
        OpenSSL_add_all_ciphers();
    
        d_pimpl->md = EVP_get_cipherbyname(type);
        if (!d_pimpl->md)
        {
            if (type == 0)
                type = "** unspecified cipher type **";
    
            throw Errno(1, "EncryptBuf `") << type << "' not available";
        }

        size_t keyLength = key.length();
        if (keyLength > EVP_MAX_KEY_LENGTH)
            keyLength = EVP_MAX_KEY_LENGTH;
    
        key.resize(EVP_MAX_KEY_LENGTH);
        iv.resize(EVP_MAX_IV_LENGTH);

        EVP_CIPHER_CTX_init(&d_pimpl->ctx);

        if 
        (
            !EVP_EncryptInit_ex(&d_pimpl->ctx, d_pimpl->md, 0,
                0, // no key yet, is entered next
                reinterpret_cast<unsigned char const *>(iv.data()))
        )
            throw Errno(1, "EncryptBuf: initialization failed");

        installKey(key, keyLength);
    
        d_pimpl->buffer = new char[bufsize];
        d_pimpl->out = new char[
                bufsize + EVP_CIPHER_CTX_block_size(&d_pimpl->ctx)]; 
        
        open();
    }
    catch (...)
    {
        delete d_pimpl;
        throw;
    }
}





