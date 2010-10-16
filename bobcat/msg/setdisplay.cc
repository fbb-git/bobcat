#include "msg.ih"

bool Msg::setDisplay(bool mode) 
{
    for_each(s_streams, s_streams + s_nStreams, 
                FnWrap::unary(setActive, mode));

    return display();
}
