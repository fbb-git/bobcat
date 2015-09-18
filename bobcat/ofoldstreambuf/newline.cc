#include "ofoldstreambuf.hh"

void OFoldStreambuf::newline()
{
    //cerr << "NEWLINE\n";

    put('\n');
    d_next = 0;
}
