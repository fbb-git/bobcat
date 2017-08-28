#include "string.ih"

bool String::qEnd(FSAData &data)
{
    ++data.begin;                       // skip the single quote
    data.state = START;                 // start from the beginning
    return true;
}
