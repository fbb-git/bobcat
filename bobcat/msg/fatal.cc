#include "msg.ih"

void FBB::fatal(ostream &out)
{
    ostringstream &os = dynamic_cast<ostringstream &>(out);

    Msg::s_out << "[Fatal] " << os.str() << endl;

    throw Errno(1);
}

