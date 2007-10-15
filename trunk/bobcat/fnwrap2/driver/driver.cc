#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

#include "../fnwrap2"

using namespace std;
using namespace FBB;

bool cmp(string &actual, string const &target)
{
    cout << "Saw " << actual << endl;

    bool ret = actual == target;
    actual += ".";
    return ret;
}

class X
{
    public:
        static bool cmp(string const &actual, string const &target)
        {
            cout << "Saw " << actual << endl;
            return actual == target;
        }
};

int main(int argc, char **argv)
{
    vector<string> vs(argv, argv + argc);

    find_if(
        vs.begin(), vs.end(),
        bind2nd(
            FnWrap2<string &, string const &, bool>(&cmp), 
            string("hello")
        )
    );

    cout << endl;

    find_if(
        vs.begin(), vs.end(),
        bind2nd(
            FnWrap2<string const &, string const &, bool>(&X::cmp), 
            string("hello")
        )
    );
}
