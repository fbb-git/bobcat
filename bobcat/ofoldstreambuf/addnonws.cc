#include "ofoldstreambuf.ih"

void OFoldStreambuf::addNonWs(int c)
{
    d_nonWs += c;
}
