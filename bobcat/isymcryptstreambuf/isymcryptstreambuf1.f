inline ISymCryptStreambuf<ENCRYPT>::ISymCryptStreambuf(
                    std::istream &in,       char const *type,
                    std::string const &key, std::string const &iv,
                    size_t bufSize,         size_t filterBufSize,
                    ENGINE *engine
        )
:
    SymCryptStreambufBase(
        &EVP_EncryptInit_ex,  &EVP_EncryptUpdate, &EVP_EncryptFinal_ex,
        in,      type, 
        key,     iv,
        bufSize, filterBufSize, 
        engine
    )
{}
