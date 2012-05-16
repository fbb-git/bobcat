#include "tempstream.ih"

TempStream::~TempStream()
{
    unlink(d_fileName.c_str());
}
