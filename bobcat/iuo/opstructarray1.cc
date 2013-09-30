#include "iuo.ih"

OptStructArray::OptStructArray(size_t n)
:
    d_n(n),
    d_opt(new OptStruct[n])
{
    d_opt[n - 1] = OptStruct{0, };
}
