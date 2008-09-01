#include "xpointer.ih"

void Xpointer::verify() const
{
    if (!s_theDisplay)
        throw Errno(1, "Can't open the display");
        
    if (!--s_counter)               // No more Xpointer objects ?
        XCloseDisplay(s_theDisplay);
}
    
