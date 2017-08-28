#include "string.ih"

// Keeps the elements that would have been returned by strtok

void String::tok(SplitPairVector *entries)
{
    auto end = remove_if(entries->begin(), entries->end(), 
        [&](SplitPair const &entry)
        {
            return entry.second == SEPARATOR || entry.first.empty();
        }
    );

    entries->resize(end - entries->begin());
}
    
