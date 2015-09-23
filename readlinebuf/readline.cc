#include "readlinebuf.hh"

char *ReadLineBuf::readLine()
{
    char *buf = readline(d_prompt.c_str());

    if (buf == 0)
        return 0;

    return nextLine(buf);
}
