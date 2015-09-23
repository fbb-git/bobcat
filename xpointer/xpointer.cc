#include "xpointer.hh"

Xpointer::Xpointer()
{
    if (s_counter++)
        return;         // One more object

    s_theDisplay = XOpenDisplay(0);

    if (!s_theDisplay)
        throw Exception(1) << "Can't open the display";
}
    
    
