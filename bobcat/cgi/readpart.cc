#include "cgi.ih"

void CGI::readPart(string *line)
{
    next(line);             // empty line following Content-Disposition

    while (true)
    {
        next(line);         // either a boundary or a field value

        if (typeOf(*line) != NO_BOUNDARY)   // it's a boundary 
            break;                          // (i.e., NOT no boundary)

                            // otherwise it's a field value
        d_param[d_contentDisposition[1]].push_back(escape(*line));
    }            
}
