#include "string.ih"

bool String::eosIn(FSAData &data)
{
    data.entries->push_back(data.entry);
    return false;
}
