#include "xpointer.ih"

Xpointer::Xpointer()
{
    if (s_counter++)
        return;         // One more object

    s_theDisplay = XOpenDisplay(0);
}
    
    
