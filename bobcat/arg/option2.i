inline size_t Arg::option(std::string *value, char const *longOption) const
{
    return option(static_cast<size_t>(0), value, longOption);
}
