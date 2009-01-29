#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <bobcat/fnwrap1c>
#include <bobcat/lc>

using namespace std;
using namespace FBB;

class Strings
{
    typedef LC<size_t, ostream &> lc;
    vector<string> d_vs;

    public:
        Strings()
        {
            d_vs.push_back("one");
            d_vs.push_back("two");
            d_vs.push_back("");
            d_vs.push_back("three");
        }

        void display(ostream &out) const
        {
            lc c(1, out);

            find_if(d_vs.begin(), d_vs.end(),
                FnWrap1c<string const &, lc &, bool>
                     (&Strings::untilEmpty, c));
        }

    private:
        static bool untilEmpty(string const &str, lc &c)
        {
            if (str.empty())
                return true;        // stop

            c.f2 << c.f1++ << " " << str << endl;

            return false;           // don't stop
        }
};

int main()
{
    Strings s;

    s.display(cout);
}
