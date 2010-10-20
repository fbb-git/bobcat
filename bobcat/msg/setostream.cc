#include "msg.ih"

void Msg::setOstream(string const &name) 
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::setOstream is DEPRECATED. Use\n"
                "setDisplay(name) instead\n"
                "\n";
    }
    setDisplay(name);
}
