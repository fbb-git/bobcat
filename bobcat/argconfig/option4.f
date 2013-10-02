inline size_t ArgConfig::option(size_t *idx, std::string *value, 
                                            char const *longOpt) const
{
    return Arg::option(idx, value, longOpt);
}
