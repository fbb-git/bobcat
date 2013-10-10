template <typename FP>
inline bool CmdFinder<FP>::match(std::string const &key) const
{
    return (this->*d_match)(key);
}
