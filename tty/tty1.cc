#include "tty.ih"

Tty::Tty()
:
    d_fd(open("/dev/tty", O_RDONLY))
{
    if (d_fd == -1)
        throw Exception{} << "Can't open '/dev/tty': " << errnodescr;

    if (tcgetattr(d_fd, &d_tty) != 0)
        throw Exception{} << "Can't get /dev/tty's attributes: " <<
                             errnodescr;
}
