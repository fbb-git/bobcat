inline bool CmdFinderBase::matchInsensitive(string const &key) const
{
    return 
        String::casecmp(d_cmd, key) == 0 
        &&
        d_cmd.length();
}
