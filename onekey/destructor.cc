#include "onekey.ih"

OneKey::~OneKey()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &d_saved);
}
