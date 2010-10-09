#include "readlinebuf.ih"

ReadLineBuf::ReadLineBuf(string const &prompt, Type type)
:
    d_history(true),
    d_prompt(prompt),
    d_buffer(0),
    d_readline(type == NO_EXPANSION ? 
                       &ReadLineBuf::readLine : &ReadLineBuf::expandLine),
    d_expansion(Expansion::ERROR)
{
     using_history();
}

