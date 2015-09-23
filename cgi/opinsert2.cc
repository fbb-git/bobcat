#include "cgi.hh"

CGI &CGI::operator<<(std::pair<char, char> range)
{
    if (!d_activated)
    {
        for(auto &target: 
                ranger(
                    d_escape + static_cast<unsigned char>(range.first),
                    d_escape + static_cast<unsigned char>(range.second) + 1
                )
        )
            target = d_escapeValue;

        d_escape['\\'] = true;
    }

    return *this;
}
