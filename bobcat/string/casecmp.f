inline int String::casecmp(std::string const &lhs, std::string const &rhs)
{
    return strcasecmp(lhs.c_str(), rhs.c_str());
}
