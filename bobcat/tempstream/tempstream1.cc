#include "tempstream.ih"

TempStream::TempStream(string const &base)
{
    char *buf = new char[base.length() + 6 + 1];

    strcpy(buf + base.length(), "XXXXXX");
    base.copy(buf, string::npos);

    int fd = mkostemp(buf, O_RDWR);

    if (fd == -1)
        throw Errno("TempStream");

    d_fileName = buf;
    delete[] buf;
    ::close(fd);

    open(d_fileName, ios::out | ios::in);
}
