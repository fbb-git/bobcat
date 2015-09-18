#include "tty.hh"

bool Tty::echo(EchoType type)
{
    struct termios tty = d_tty; 

    switch (type)
    {
        case ON:
            tty.c_lflag |= ECHO;
        break;

        case OFF:
            tty.c_lflag &= ~ECHO;
        break;

        default:
        break;
    }

    return tcsetattr(d_fd, TCSANOW, &tty) == 0;
}
