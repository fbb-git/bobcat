#include "msg.ih"

void FBB::showOpen()
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::open(...) functions are DEPRECATED and will be "
                                                            "removed from\n" 
                "BOBCAT in a future release. Use FBB::Errno::open functions "
                                                                "instead\n"
                "\n";
    }
}
