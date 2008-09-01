#include "onekey.ih"

OneKey::~OneKey()
{
    if (d_err < 2)
        tcsetattr(STDIN_FILENO, TCSANOW, &d_saved);

    verify();
}
