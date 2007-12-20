#include "arg.ih"

void Arg::addCharOption(int option)
{
    d_optv[option].push_back(optarg ? optarg : "");
    ++d_nOptv;
}
