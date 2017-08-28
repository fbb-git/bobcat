#include "string.ih"

bool String::dqIn(FSAData &data)
{
    ++data.begin;
    data.entry.second = DQUOTE;
    data.state = DQSTRING;
    return true;
}
