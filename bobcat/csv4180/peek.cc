#include "csv4180.ih"

CSV4180::CharType CSV4180::peek()
{
    if (d_begin == d_end)
        return EOS;

    switch (int ch = *d_begin)
    {
        case '\r':  return CR;
        case '"':   return DQUOTE;
        default:    return ch == d_fieldSep ? FIELDSEP : CHAR;
    }
}
