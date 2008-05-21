#include "cgi.ih"

CGI &CGI::operator<<(std::pair<char, char> range)
{
    if (!d_activated)
    {
        for_each(d_escape + static_cast<unsigned char>(range.first),
             d_escape + static_cast<unsigned char>(range.second) + 1,
             *this, &CGI::init);

        d_escape['\\'] = true;
    }

    return *this;
}
