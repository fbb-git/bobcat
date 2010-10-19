#include "msg.ih"

void FBB::spool(ostream &out)
{
    imsg << dynamic_cast<ostringstream &>(out).str() << flush;
}

