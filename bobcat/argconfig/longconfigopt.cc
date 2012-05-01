#include "argconfig.ih"

pair<ArgConfig::const_RE_iterator, ArgConfig::const_RE_iterator>
        ArgConfig::longConfigOpt(string const &longOpt)
{
    string pattern = "^\\s*" + longOpt + ":?(\\s|$)";

    return beginEndRE(pattern);
}
