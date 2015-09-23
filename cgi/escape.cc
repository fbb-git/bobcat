#include "cgi.hh"

string CGI::escape(string const &text)
{
    string ret = text;

    for (size_t idx = ret.length(); idx--; )
    {
        if (d_escape[static_cast<unsigned char>(ret[idx])])
            ret.insert(idx, "\\");
    }
    return ret;
}
