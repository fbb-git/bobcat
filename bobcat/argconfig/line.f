inline std::string const &ArgConfig::line(size_t idx) const
{
    return ConfigFile::operator[](idx);
}
