inline size_t CaseHash::operator()(std::string const &key) const
{
    return std::hash<std::string>()(FBB::String::lc(key));
}
