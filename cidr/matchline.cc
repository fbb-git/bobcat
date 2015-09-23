#include "cidr.hh"

// Here we get one line, and want to obtain all its elements matching 
// the pattern. 
// Return true once a match is found, else false

bool Cidr::matchLine(string const &line)    //, Cidr &cidr)
{
    static Pattern sl_pattern("\\b\\d+\\.\\d+\\.\\d+\\.\\d+\\b");

    string inspect(line);
    auto end = d_cidr.end();

    while (sl_pattern << inspect)   // find the first match in 'inspect'
    {
        string const &matched = sl_pattern.matched();

        d_iter = find_if(
                    d_cidr.begin(), end, 
                    [&, this](MaskPair const &mp)
                    {
                        return this->compare(mp, matched);
                    }
                );

        if (d_iter != end)
            return true;

        inspect = sl_pattern.beyond();
    }

    return false;        
}
