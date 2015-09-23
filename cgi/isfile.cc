#include "cgi.hh"

bool CGI::isFile(string const &line)
try
{
    d_contentDisposition.match(line);   // match the content disposition

    try
    {
        d_contentFile.match(d_contentDisposition.beyond());
        return true;
    }
    catch(...)
    {
        return false;                   // no file upload
    }
}
catch (...)
{
    d_status = "Content-Disposition not recognized in: " + line;
    throw false;
}

