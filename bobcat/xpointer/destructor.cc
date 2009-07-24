#include "xpointer.ih"

Xpointer::~Xpointer()
{
    if (!--s_counter)               // No more Xpointer objects ?
        XCloseDisplay(s_theDisplay);
}
    
