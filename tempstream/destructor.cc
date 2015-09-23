#include "tempstream.hh"

TempStream::~TempStream()
{
    unlink(d_fileName.c_str());
}
