#include "onekey.ih"

OneKey::~OneKey()
{
    if (d_err < 2)
        tcsetattr(STDIN_FILENO, TCSANOW, &d_saved);

    if (!s_ok)
        s_ok = bobcatVerify("OneKey");
}
