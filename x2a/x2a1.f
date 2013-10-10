template <typename T>                   // initialize from 
inline X2a::X2a(T const &x)             // (insertable) type
{
    s_lastFail = (*this << x).fail();
}
