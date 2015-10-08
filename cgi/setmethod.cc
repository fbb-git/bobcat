#include "cgi.ih"

void CGI::setMethod()
{
    char const *cp = (*this)["REQUEST_METHOD"];

    if (cp)
    {
        string meth(cp);

        if (meth == "GET")
        {
            d_method = GET;
            return;
        }
        if (meth == "POST")
        {
            if ((cp = (*this)["CONTENT_LENGTH"]))
                d_contentLength = A2x(cp);

            if ((cp = (*this)["CONTENT_TYPE"]) != 0)
            {
                string type(cp);
                string::size_type pos;

                if 
                (
                    type.find("multipart/form-data") == 0 
                    &&
                    (pos = type.find("boundary=")) != string::npos
                )
                {                               // don't count trailing \0
                    d_boundary = type.substr(pos + sizeof("boundary=") - 1); 
                    d_boundary.insert(0, "--"); // actual boundary has two
                                                // additional - chars
                }
            }
            d_method = POST;
            return;
        }
    }
    d_status = "GET/POST REQUEST_METHOD not found";
}

