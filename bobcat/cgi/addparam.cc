#include "cgi.ih"

namespace
{
    Pattern pattern("([^=]*)=(.*)");
}

void CGI::addParam(string const &param)
try
{
    pattern.match(param);
    d_param[pattern[1]].push_back(escape(unPercent(pattern[2])));
}
catch (Errno const &err)
{}
