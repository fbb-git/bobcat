#include "string.ih"

bool String::sepIn(FSAData &data)
{
    data.entries->push_back(data.entry);    // store the current entry
                                            // store the separator
    data.entries->push_back(SplitPair{ *data.begin++, SEPARATOR });

    data.entry = SplitPair{};           // start a new entry

    return true;
}
