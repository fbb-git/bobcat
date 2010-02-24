#include "configfile.ih"

vector<string>::const_iterator ConfigFile::find(string const &target) const
{
    return !d_caseSensitive ?
        findRE(target)
    :
        find_if(begin(), end(), FnWrap1c<string const &, string &, bool>
                                (contains, const_cast<string &>(target)));
                        // the const_cast is needed because Wrap1c's 2nd
                        // parameter is non-const. It is ok, since we know
                        // that `target' isn't modified by `contains'
}
