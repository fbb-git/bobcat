#include "string.ih"

bool String::chIn(FSAData &data)
{
    data.entry.first += *data.begin++;    // store the character
    return true;
}
