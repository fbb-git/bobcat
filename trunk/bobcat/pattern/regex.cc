#include "pattern.ih"

Pattern::Regex::Regex(string pattern, int options)
:
    d_referenceCount(1)
{    
    PerlSetFSA().convert(pattern);

    int errcode = regcomp(&d_regex, pattern.c_str(), options);

    if (errcode)
    {
        auto_ptr<char> buffer(new char[100]);

        regerror(errcode, &d_regex, buffer.get(), 100);

        throw Errno(errcode, "Pattern::Pattern(") << 
                    insertable << pattern << "): " << buffer.get() << 
                    throwable;
    }

    s_converted = pattern;          // make the converted pattern available
                                    // to who's interested in it.
}
