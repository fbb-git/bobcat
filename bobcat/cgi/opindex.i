inline char const *CGI::operator[](std::string const &key) const
{
    return getenv(key.c_str());
}
