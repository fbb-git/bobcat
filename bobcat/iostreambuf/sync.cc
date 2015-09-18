#include "iostreambuf.hh"

int IOStreambuf::sync()
{        
    return pSync();
}
