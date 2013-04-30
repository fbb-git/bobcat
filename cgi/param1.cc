#include "cgi.ih"

std::string CGI::param1(std::string const &variable)
{
    auto &vect = param(variable);

    string ret;

    if (not vect.empty())
        ret = vect[0];

    return ret;
}

