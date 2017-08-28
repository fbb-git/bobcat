#include "string.ih"

// Keeps the elements that would have been returned by strtok

void String::str(SplitPairVector *entries)
{
    auto end = remove_if(entries->begin(), entries->end(), 
        [&](SplitPair const &entry)
        {
            return entry.second == SEPARATOR;
        }
    );

    entries->resize(end - entries->begin());
}
    
