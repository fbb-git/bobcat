#include "xpointer.ih"

Xpointer::Xpointer()
{
    if (s_theDisplay)
        return;

    s_theDisplay = std::unique_ptr<Display, DeleterType>
                                    (XOpenDisplay(0), deleter);

    if (!s_theDisplay)
        throw Errno(1, "Can't open the display");
}
    
    
