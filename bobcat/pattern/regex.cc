#include "pattern.ih"

Pattern::Regex::Regex(string pattern, int options) throw (Errno)
:
    d_referenceCount(1)
{    
    static PerlSetFSA fsa;
    fsa.convert(pattern);

    int errcode = regcomp(&d_regex, pattern.c_str(), options);
    if (errcode)
    {
        char buffer[100];
    
        regerror(errcode, &d_regex, buffer, 100);
        throw Errno(errcode, "Pattern::Pattern(...)") << 
                    insertable << buffer << throwable;
    }
}
