#include "csv4180.ih"

CSV4180::CharType CSV4180::peek()
{
    if (d_begin == d_end)
        return EOS;

    switch (*d_begin)
    {
        case '\r':  return CR;
        case '"':   return DQUOTE;
        case ',':   return COMMA;
        default:    return CHAR;
    }
}
