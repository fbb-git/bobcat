inline char const **Glob::mend() const
{
    return const_cast<char const **>(d_share->end);
}
