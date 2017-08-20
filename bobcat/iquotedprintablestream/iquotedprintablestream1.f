template <CryptType type>
IQuotedPrintableStream<type>::IQuotedPrintableStream(std::istream &in, 
                                                     size_t bufSize)
:
    IQuotedPrintableStreambuf<type>(in, bufSize),
    std::istream(this)
{}
