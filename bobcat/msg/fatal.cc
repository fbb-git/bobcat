#include "msg.ih"

void FBB::fatal(ostream &out)
{
    fmsg << dynamic_cast<ostringstream &>(out).str() << endl;
}

