#include "onekey.ih"

int OneKey::get() const
{
    int c = cin.get();          // read the char

    if (d_useEcho)
        cout << static_cast<char>(c) << flush;

    return c;                     
}
