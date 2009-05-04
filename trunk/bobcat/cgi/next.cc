#include "cgi.ih"

void CGI::next(string *line)
{
    if (!getline(cin, *line))
    {
        d_status = "Invalid multipart/form-data";
        throw false;
    }
}
