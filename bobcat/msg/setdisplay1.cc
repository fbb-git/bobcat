#include "msg.ih"

bool Msg::setDisplay(bool mode) 
{
    bool old = display();

    for_each(s_msgStream, s_msgStream + s_sizeofType, 
                FnWrap::unary(setActive, mode));

    return old;
}
