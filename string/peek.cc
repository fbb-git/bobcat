#include "string.ih"

String::CharType String::peek(FSAData &data)
{
    if (data.begin == data.end)
        return CharType::EOS;
        
    if (data.separators.find(*data.begin) != string::npos)
        return CharType::SEPARATOR;

    switch (*data.begin)
    {
        case '"':   return CharType::DQUOTE;
        case '\'':  return CharType::SQUOTE;
        case '\\':  return CharType::ESCAPE;
        default:    return CharType::CHAR;
    }
}

