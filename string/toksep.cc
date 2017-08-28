#include "string.ih"

// Keep the elements that would have been returned by strtok, and indicate
// separators by empty strings

void String::toksep(SplitPairVector *entries)
{
    auto end = remove_if(entries->begin(), entries->end(), 
        [&](SplitPair const &entry)
        {
            return entry.first.empty();
        }
    );
    
    entries->resize(end - entries->begin());

    for (auto &entry: *entries)
    {
        if (entry.second == SEPARATOR)
            entry.first.clear();
    }
}

    
