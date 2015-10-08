#include "cgi.ih"

CGI::Boundary CGI::typeOf(string const &line) const
{
    if (line.find(d_boundary) != 0)
        return NO_BOUNDARY;

    if (line.substr(d_boundary.length(), 2) == "--")    // end of data
        return END_BOUNDARY;

    return BOUNDARY;
}
