template <typename Type>
inline Type A2x::to()
{
    Type t;

    return (s_lastFail = (*this >> t).fail()) ? Type() : t;
}
