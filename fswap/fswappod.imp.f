
template <typename Type>
FSwapPOD<Type>::FSwapPOD(char *buffer, char *from, Type &lhs, Type &rhs)
:
    d_buffer(buffer),
    d_from(from),
    d_lhs(lhs),
    d_rhs(rhs)
{}

template <typename Type>
inline FSwapPOD<Type> PODfactory(char *buffer, char *from, 
                                 Type &lhs, Type &rhs)
{
    return FSwapPOD<Type>(buffer, from, lhs, rhs);
}
