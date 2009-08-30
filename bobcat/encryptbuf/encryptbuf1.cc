#include "encryptbuf.ih"

EncryptBuf::EncryptBuf(ostream &outStream, char const *type, 
                        string const &key, string const &iv, size_t bufsize)
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
    
            throw Errno(1, "EncryptBuf `") << insertable << type << 
                                            "' not available" << throwable;
        }
    
        EVP_CIPHER_CTX_init(&d_pimpl->ctx);
    
        if 
        (
            !EVP_EncryptInit_ex(&d_pimpl->ctx, d_pimpl->md, 0,
                reinterpret_cast<unsigned char const *>(key.c_str()), 
                reinterpret_cast<unsigned char const *>(iv.c_str()))
        )
            throw Errno(1, "EncryptBuf: initialization failed");
    
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





