#include "pattern.hh"

Pattern::Regex::Regex(string pattern, int options)
:
    d_referenceCount(1)
{    
    PerlSetFSA().convert(pattern);

    int errcode = regcomp(&d_regex, pattern.c_str(), options);

    if (errcode)
    {
        unique_ptr<char> buffer(new char[100]);

        regerror(errcode, &d_regex, buffer.get(), 100);

        throw Exception(errcode) << "Pattern::Pattern(" << pattern << "): " << 
                                                                buffer.get();
    }

    s_converted = pattern;          // make the converted pattern available
                                    // to who's interested in it.
}
