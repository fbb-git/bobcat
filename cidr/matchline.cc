#include "cidr.ih"

// Here we get one line, and want to obtain all its elements matching 
// the pattern. 
// Return true once a match is found, else false

bool Cidr::matchLine(string const &line, Cidr &cidr)
{
    static Pattern sl_pattern("\\b\\d+\\.\\d+\\.\\d+\\.\\d+\\b");

    string inspect(line);
    auto end = cidr.d_cidr.end();

    while (sl_pattern << inspect)   // find the first match in 'inspect'
    {
        string const &matched = sl_pattern.matched();

        cidr.d_iter = find_if(
                          cidr.d_cidr.begin(), end, 
                          FnWrap::unary(compare, cidr, matched)
                      );

        if (cidr.d_iter != end)
            return true;

        inspect = sl_pattern.beyond();
    }

    return false;        
}
