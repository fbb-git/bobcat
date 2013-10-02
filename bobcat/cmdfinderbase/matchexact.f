inline bool CmdFinderBase::matchExact(string const &key) const
{
    return d_cmd == key && d_cmd.length();
}
