#include "sharedstream.hh"

SharedStream::SharedStream()
:
    istream(this),
    ostream(this)
{}
 
