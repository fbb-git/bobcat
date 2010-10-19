#include "msg.ih"

void FBB::warning(ostream &out)
{
    wmsg << dynamic_cast<ostringstream &>(out).str() << endl;
}

