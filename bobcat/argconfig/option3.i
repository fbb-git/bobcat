inline size_t ArgConfig::option(size_t idx, std::string *value, 
                                            char const *longOption) const
{
    return Arg::option(idx, value, longOption);
}
