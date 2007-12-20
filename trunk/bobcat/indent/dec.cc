#include "indent.ih"

void FBB::Indent::dec()
{
    Indent::s_width = Indent::s_width > Indent::s_inc ? 
                        Indent::s_width - Indent::s_inc
                    :
                        0;
}

