#include "cgi.hh"

string CGI::dos2unix(string const &text)
{
    string ret(text);
    string::size_type pos = 0;

    while (true)
    {
        pos = ret.find("\r\n", pos);
        if (pos == string::npos)
            return ret;
        ret.erase(pos, 1);
    }
}


