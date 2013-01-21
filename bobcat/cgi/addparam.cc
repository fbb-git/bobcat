#include "cgi.ih"

void CGI::addParam(string const &param)
try
{
    static     Pattern pattern("([^=]*)=(.*)");

    pattern.match(param);
    d_param[pattern[1]].push_back(escape(unPercent(pattern[2])));
}
catch (std::exception const &exc)
{}
