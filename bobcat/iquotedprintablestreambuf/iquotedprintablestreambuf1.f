inline IQuotedPrintableStreambuf<ENCRYPT>::IQuotedPrintableStreambuf(
            std::istream &in, size_t bufSize)
:
    QPStreambufBase(in, bufSize)
{
    doEncode();
}
