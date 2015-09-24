#include "cgi.ih"

void CGI::report() const
{
    if (d_status.length() == 0)
        return;

    cout << "FBB::CGI: " << d_status << endl;

    throw Exception(1) << "FBB::CGI: Error(s) in uploaded form data";
}
