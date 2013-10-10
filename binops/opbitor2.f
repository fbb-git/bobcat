template <typename LHS, typename RHS>
inline typename FBB::Use<LHS, RHS>::type operator|(LHS const &lhs, 
                                                   RHS const &rhs)
{
    typename FBB::Use<LHS, RHS>::type tmp(lhs);
    tmp |= rhs;
    return tmp;
}
