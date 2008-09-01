#include "arg.ih"

void Arg::addCharOption()
{
    d_optv[d_getOpt].push_back(optarg ? optarg : "");
    ++d_nOptv;
}
