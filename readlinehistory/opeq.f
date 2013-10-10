inline bool ReadLineHistory::const_iterator::operator==(
                                            const_iterator const &rhs) const
{
    return d_idx == rhs.d_idx;
}
