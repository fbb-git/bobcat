#include "xpointer.hh"

Xpointer::~Xpointer()
{
    if (!--s_counter)               // No more Xpointer objects ?
        XCloseDisplay(s_theDisplay);
}
    
