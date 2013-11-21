inline std::ostream &operator<<(std::ostream &out, SharedPos const &sharedPos)
{
    return sharedPos.insert(out);
}
