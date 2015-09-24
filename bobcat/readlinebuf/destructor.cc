#include "readlinebuf.ih"

ReadLineBuf::~ReadLineBuf()
{
    delete[] d_buffer;
    if (d_history)
        clear_history();
}
