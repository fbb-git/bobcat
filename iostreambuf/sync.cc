#include "iostreambuf.ih"

int IOStreambuf::sync()
{        
    return pSync();
}
