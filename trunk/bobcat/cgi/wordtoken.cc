#include "cgi.ih"

size_t CGIFSA::wordToken()
{
    d_buffer.clear();

    while (islower(d_in.peek()))        // read all lowercase chars
        d_buffer += d_in.get();

    if (!d_buffer.size())               // if none read, return the next char
        return charToken();             

                                        // look for a character class name
    PairCPPFunP const *ret = find_if(s_charClass, s_charClassEnd, 
            FnWrap::unary(isFirst, d_buffer));

    if (ret == s_charClassEnd)          // no character class found
        return static_cast<unsigned char>(*d_buffer.rbegin());

    d_setIdx = ret - s_charClass;       // charclass found

    return SET;                         // return `set found'
}

