#include "configfile.ih"

bool RE_iterator::reMatch(string &line, RE_iterator &re_iter)
{
    return re_iter.d_pattern << line;
}
