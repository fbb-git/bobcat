inline
IBase64Streambuf<DECRYPT>::IBase64Streambuf(std::istream &in, size_t bufSize)
:
    Base64StreambufBase(in, bufSize)
{
    doDecrypt();
}
