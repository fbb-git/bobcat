#include "gethostent.hh"

hostent const *GetHostent::gethostent(char const *prefix, string const &host) 
{
    static Pattern address("(\\d+\\.){3}\\d+"); // 4 series of . separated
                                                // digits.
    struct hostent *hp;

    try
    {
        address.match(host);        // numerical address?

        in_addr_t adds = inet_addr(host.c_str());    
                                    // returns in_addr_t, which 
                                    // is a conversion of the d.d.d.d notation
                                    // to a binary value.

        hp = gethostbyaddr(reinterpret_cast<char const *>(&adds), 
                            sizeof(in_addr), AF_INET);
    }
    catch(...)
    {
        hp = gethostbyname(host.c_str());
    }

    if (!hp)
        hosterror(prefix);      // throws Exception

    return hp;
}







