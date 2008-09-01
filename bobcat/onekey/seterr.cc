#include "onekey.ih"

void OneKey::setErr(int nr, char const *txt)
{
    d_err = nr;
    d_msg = txt;
}
