template <typename Class>
inline Class operator-(Class &&lhs, Class const &rhs)
{
    return std::move(lhs -= rhs);
}
