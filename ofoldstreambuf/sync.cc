#include "ofoldstreambuf.hh"

int OFoldStreambuf::sync()
{
    return pSync();
}
