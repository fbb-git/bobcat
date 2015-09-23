#include "cgi.hh"

void CGI::setParam()
{
    if (d_activated || d_status.length() != 0)
        return;

    switch (d_method)
    {
        case GET:
            get();
        break;

        case POST:
            post();
        break;

        default:
        break;
    }

    report();
    d_activated = true;
}
