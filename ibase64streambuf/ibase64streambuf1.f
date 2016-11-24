inline
IBase64Streambuf<ENCRYPT>::IBase64Streambuf(std::istream &in, size_t bufSize)
:
    Base64StreambufBase(in, bufSize)
{
    doEncrypt();
}
