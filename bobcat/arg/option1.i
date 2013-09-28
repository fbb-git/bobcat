inline size_t Arg::option(std::string *value, int optChar) const
{
    return option(static_cast<size_t>(0), value, optChar);
}
