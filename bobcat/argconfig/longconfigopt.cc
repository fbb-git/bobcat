#include "argconfig.hh"

ArgConfig::RE_iteratorPair ArgConfig::longConfigOpt(string const &longOpt)
{
    string pattern = "^\\s*" + longOpt + ":?(\\s|$)";

    return beginEndRE(pattern);
}
