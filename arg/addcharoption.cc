#include "arg.hh"

void Arg__::addCharOption()
{
    d_optv[d_getOpt].push_back(optarg ? optarg : "");
    ++d_nOptv;
}
