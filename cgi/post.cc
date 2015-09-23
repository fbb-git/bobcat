#include "cgi.hh"

void CGI::post()
{
    if (!d_boundary.length())   // POSTed forms not using multipart/form-data 
    {
        get();                  // offer GET-like data via cin
        return;
    }

    multipartFormData();        // process the multipart/form-data
}
