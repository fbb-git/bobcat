#include "xpointer.ih"

Xpointer::~Xpointer()
{
    verify();

    if (!--s_counter)               // No more Xpointer objects ?
        XCloseDisplay(s_theDisplay);
}
    
