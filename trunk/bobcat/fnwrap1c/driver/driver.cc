#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../fnwrap1c"

using namespace std;
using namespace FBB;

class Strings
{
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
            SContext c = {1, out};
            find_if(d_vs.begin(), d_vs.end(),
                FnWrap1c<string const &, SContext &, bool>
                     (&Strings::untilEmpty, c));
        }

    private:
        struct SContext
        {
            size_t nr;
            ostream &out;
        };

        static bool untilEmpty(string const &str, SContext &c)
        {
            if (str.empty())
                return true;        // stop

            c.out << c.nr++ << " " << str << endl;
            return false;           // don't stop
        }
};

int main()
{
    Strings s;

    s.display(cout);
}
