#include "sharedstream.ih"

SharedStream::SharedStream()
:
    istream(this),
    ostream(this)
{}
 
