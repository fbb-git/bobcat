inline bool CmdFinderBase::matchInsensitive(string const &key) const
{
    return 
        strcasecmp(d_cmd.c_str(), key.c_str()) == 0 
        &&
        d_cmd.length();
}
