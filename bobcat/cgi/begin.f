inline CGI::MapStringVector::const_iterator CGI::begin()
{
    setParam();
    return d_param.begin();
}
