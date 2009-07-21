#include "xpointer.ih"

bool Xpointer::get(int *x, int *y) const
{
    Window rootret;
    Window child;
    Window root = DefaultRootWindow(s_theDisplay.get());
    unsigned int keys;
    int dum_x;
    int dum_y;

    return XQueryPointer(s_theDisplay.get(), root, &rootret, &child,
                                             x, y, &dum_x, &dum_y, &keys);
}
