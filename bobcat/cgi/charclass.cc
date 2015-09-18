#include "cgi.hh"

void CGIFSA::charClass()       // saw:     [ : charclass : ]
{   
    while (true)
    {
        char c = d_stack.top();
        d_stack.pop();
        if (c == '[')
            break;
    }

    int (*predicate)(int) = s_charClass[d_setIdx].second;

    for (int idx = 0; idx < 255; ++idx)
    {
        if ((*predicate)(idx))
            setEscape(idx);
    }
}

