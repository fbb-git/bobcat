template <CryptType cryptType>
ISymCryptStream<cryptType>::ISymCryptStream(
    std::istream &in,       char const *type,
    std::string const &key, std::string const &iv,
    size_t bufSize,         size_t filterBufSize,
    ENGINE *engine)
:
    ISymCryptStreambuf<cryptType>(
        in,      type, 
        key,     iv, 
        bufSize, filterBufSize, 
        engine
    ),
    std::istream(this)
{}
