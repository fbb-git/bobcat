#include "xpointer.ih"

bool Xpointer::set(int x, int y) const
{
    Window root = DefaultRootWindow(s_theDisplay.get());
    XWindowAttributes XWA;              // get root window info
        
    if (!XGetWindowAttributes(s_theDisplay.get(), root, &XWA))
        return false;                   // failure return

    if (x < 0)
        x += XWA.width;

    if (y < 0)
        y += XWA.height;

    XWarpPointer(s_theDisplay.get(), root, root, 0, 0, 
                                            XWA.width, XWA.height, x, y);
    XFlush(s_theDisplay.get());
    return true;
}
