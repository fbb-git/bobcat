#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../fnwrap"

// to compile: g++ --std=c++0x driver.cc
// use g++ >= 4.4

using namespace std;
using namespace FBB;

class Strings
{
    vector<string> d_vs;

    public:
        Strings()
        :
            d_vs({"one", "two", "", "three"})
        {}

        void display(ostream &out) const
        {
            size_t nr = 1;
            find_if(d_vs.begin(), d_vs.end(),
                context(untilEmpty, nr, out));
        }

        void display() const
        {
            for_each(d_vs.begin(), d_vs.end(),
                context(toCout));
        }

        void show(ostream &out) const
        {
            size_t nr = 1;
            for_each(d_vs.begin(), d_vs.end(),
                context(all, nr, out));
        }

        void accu(ostream &out) const
        {
            size_t nr = 1;
            equal(d_vs.begin(), d_vs.end(), d_vs.rbegin(),
                context(cmpfun2, nr, out));
        }

        void count()
        {
            size_t nLines = 0;
            cout << "Number of counts: " <<
                count_if(d_vs.begin(), d_vs.end(), 
                         context(counter, cout, nLines));
            cout << '\n' << 
                    nLines << " lines processed\n";
        }

    private:
        static bool cmpfun2(string const &str1, string const &str2, 
                        size_t &nr, ostream &out)
        {
            out << nr++ << " " << str1 << " and " << str2 << '\n';
            return true;           // don't stop
        }

        static void toCout(string const &str)
        {
            cout << "toCout: " << str << '\n';
        }

        static bool untilEmpty(string const &str, size_t &nr, ostream &out)
        {
            if (str.empty())
                return true;        // stop

            out << nr++ << " " << str << '\n';
            return false;           // don't stop
        }
        static void all(string const &str, size_t &nr, ostream &out)
        {
            out << nr++ << " " << str << '\n';
        }
        static bool counter(string const &str, ostream &out, size_t &nLines)
        {
            out << "Line nr " << ++nLines << ": " << str;
            if (str.find('t') != string::npos)
            {
                out << ", contains 't'\n";
                return true;
            }
            else
            {
                out << ", no 't'\n";
                return false;
            }
        }
};

int main()
{
    Strings s;

    s.display(cout);
    cout << "========\n";
    s.display();
    cout << "========\n";
    s.show(cout);
    cout << "========\n";
    s.accu(cout);
    cout << "========\n";
    s.count();
}






