#include "cgi.hh"

void CGI::setQuery()
{
    switch (d_method)
    {
        case GET:
            if (char const *cp = (*this)["QUERY_STRING"])
                d_query = cp;
        break;

        case POST:
            if (d_boundary.length() == 0)
            {
                unique_ptr<char> cp(new char[d_contentLength]);
            
                if (!cin.read(cp.get(), d_contentLength))
                    d_status = "invalid CONTENT_LENGTH in POSTed form";
                else
                    d_query.assign(cp.get(), d_contentLength);
            }
        break;

        default:
        break;
    }
}
