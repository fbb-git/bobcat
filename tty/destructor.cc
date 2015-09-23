#include "tty.hh"

Tty::~Tty()
{
    close(d_fd);
}
