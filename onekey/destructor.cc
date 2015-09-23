#include "onekey.hh"

OneKey::~OneKey()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &d_saved);
}
