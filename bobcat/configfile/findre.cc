#include "configfile.ih"

namespace
{
    class Lookup
    {
        Pattern &d_pat;
        
        public:
            Lookup(Pattern &pat)
            :
                d_pat(pat)
            {}
            bool operator()(string const &line)
            {
                try
                {
                    d_pat.match(line);
                    return true;
                }
                catch(...)
                {
                    return false;
                }
            }
    };        
}

vector<string>::const_iterator ConfigFile::findRE(string const &re) const
{
    Pattern pattern(re, d_caseSensitive);

    return find_if(begin(), end(), Lookup(pattern));
}
