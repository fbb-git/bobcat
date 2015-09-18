#include "readlinebuf.hh"

ReadLineBuf::ReadLineBuf(string const &prompt, Type type)
:
    d_history(true),
    d_prompt(prompt),
    d_buffer(0),
    d_readline(type == DONT_EXPAND_HISTORY ? 
                       &ReadLineBuf::readLine : &ReadLineBuf::expandLine),
    d_timestamp(0),
    d_expansion(ERROR)
{
     using_history();
}

