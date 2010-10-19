#include "msg.ih"

void FBB::err(ostream &out)
{
    emsg << dynamic_cast<ostringstream &>(out).str() << endl;
}
