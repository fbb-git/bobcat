#include "arg.ih"

void Arg::addLongOption(string const &longName)
{
    d_longOptv[longName].push_back(optarg ? optarg : "");
    ++d_nLongOptions;
}
