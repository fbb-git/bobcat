#include "msg.ih"

void Msg::setOstream(string const &name) 
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::setOstream is DEPRECATED. Use "
                                                "imsg.reset(name) instead\n"
                "\n";
    }
    imsg.reset(name);
}
