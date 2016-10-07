#include "gethostent.ih"

hostent const *GetHostent::gethostent(char const *prefix, string const &host) 
{
                                    // 4 series of . separated digits.
    Pattern address("(\\d+\\.){3}\\d+"); 

    try
    {
        address.match(host);        // numeric address if match succeeds
        solveName(prefix, host);    // solve name from address
    }
    catch(...)
    {
        solveAddress(prefix, host); // solve address from name
    }

    return &s_hp;
}







