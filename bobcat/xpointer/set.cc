#include "xpointer.hh"

bool Xpointer::set(int x, int y) const
{
    Window root = DefaultRootWindow(s_theDisplay);
    XWindowAttributes XWA;              // get root window info
        
    if (!XGetWindowAttributes(s_theDisplay, root, &XWA))
        return false;                   // failure return

    if (x < 0)
        x += XWA.width;

    if (y < 0)
        y += XWA.height;

    XWarpPointer(s_theDisplay, root, root, 0, 0, XWA.width, XWA.height, x, y);
    XFlush(s_theDisplay);
    return true;
}

