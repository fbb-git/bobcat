inline bool CaseEqual::operator()(std::string const &s1, 
                                        std::string const &s2) const
{ 
    return FBB::String::casecmp(s1, s2) == 0;
}
