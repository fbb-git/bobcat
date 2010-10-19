#include "msg.ih"

void FBB::info(ostream &out)
{
    imsg << dynamic_cast<ostringstream &>(out).str() << endl;
}

