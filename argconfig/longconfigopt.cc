#include "argconfig.ih"

ArgConfig::const_RE_iterator ArgConfig::longConfigOpt(string const &longOpt)
{
    string pattern = "^\\s*" + longOpt + ":?(\\s|$)";

    return beginRE(pattern);
}
