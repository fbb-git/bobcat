inline bool ReadLineHistory::const_iterator::operator!=(
                                            const_iterator const &rhs) const
{
    return not (*this == rhs);
}
