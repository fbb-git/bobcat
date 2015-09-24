#include "cgi.ih"

void CGI::multipartFormData() 
try
{
    string line;
    
    next(&line);                                // enter while with the next
                                                // available line
    while (true)
    {
        switch (typeOf(line))                   // handle the line-type
        {
            case END_BOUNDARY:
            return;

            default:                            // no boundary, try the next
                next(&line);
            continue;

            case BOUNDARY:
                next(&line);                    // line beyound the boundary
                if (isFile(line))
                    upload(&line);              // upload a file
                else
                    readPart(&line);            // handle a plain part
            break;
            // upload() and readPart() return the next line to process         
        }
    }
}
catch (...)
{}
