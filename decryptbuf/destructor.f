inline DecryptBufImp::~DecryptBufImp()
{
    EVP_CIPHER_CTX_free(ctx);
    delete [] buffer;
    delete [] out;
}
