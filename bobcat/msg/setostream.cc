#include "msg.ih"

void Msg::setOstream(string const &name) 
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "FBB::Msg::setOstream is deprecated. Use\n"
                "setDisplay(name) instead\n";
    }
    setDisplay(name);
}
