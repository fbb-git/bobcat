#include "tty.ih"

Tty::~Tty()
{
    close(d_fd);
}
