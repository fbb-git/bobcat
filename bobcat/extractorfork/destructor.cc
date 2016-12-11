#include "extractorfork.ih"

ExtractorFork::~ExtractorFork()
{
    rdbuf(0);                       // remove the buffer from the istream
}
