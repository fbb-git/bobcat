inline IQuotedPrintableStreambuf<DECRYPT>::IQuotedPrintableStreambuf(
            std::istream &in, size_t bufSize)
:
    QPStreambufBase(in, bufSize)
{
    doDecode();
}
