#include "msg.ih"

void Msg::setOstream(string const &name) 
{
    setDisplay(INFO, name);
    setDisplay(WARNING, sbuf(INFO));
    setDisplay(ERROR,   sbuf(INFO));
    setDisplay(FATAL,   sbuf(INFO));
}
