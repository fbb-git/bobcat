#include "readlinebuf.ih"

ReadLineBuf::ReadLineBuf(string const &prompt)
:
     d_history(true),
     d_prompt(prompt),
     d_buffer(0)
{
     using_history();
}

