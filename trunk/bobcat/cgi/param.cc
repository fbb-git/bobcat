#include "cgi.ih"

std::vector<std::string> const &CGI::param(std::string const &variable)
{
    setParam();
    
    MapStringVector::const_iterator iter = d_param.find(variable);

    return iter == d_param.end() ? s_empty : iter->second;
}

