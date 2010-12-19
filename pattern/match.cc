#include "pattern.ih"

void Pattern::match(string const &text, int options)
{
    int errcode = regexec(&d_regex->d_regex, text.c_str(), 
                            d_nSub, d_subExpression, options);

    if (errcode)
        throw Errno("Pattern::match()") << insertable << "no match" <<
                                                                throwable; 
    d_text = text;

    for (d_beyondLast = d_nSub; d_beyondLast--; )
    {
        if (d_subExpression[d_beyondLast].rm_so != -1)
        {
            ++d_beyondLast;
            return;
        }            
    }
}

