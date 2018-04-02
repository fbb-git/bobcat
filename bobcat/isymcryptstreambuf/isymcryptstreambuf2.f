inline ISymCryptStreambuf<DECRYPT>::ISymCryptStreambuf(
            std::istream &in, char const *type,
            std::string const &key, std::string const &iv, 
            size_t bufSize, size_t filterBufSize, 
            ENGINE *engine)
:
    SymCryptStreambufBase(
        &EVP_DecryptInit_ex, &EVP_DecryptUpdate, &EVP_DecryptFinal_ex, 
        in,      type, 
        key,     iv,
        bufSize, filterBufSize, 
        engine
    )
{}
