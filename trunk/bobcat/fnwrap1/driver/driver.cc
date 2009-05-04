#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "../fnwrap1"

using namespace std;
using namespace FBB;

bool cmp(string &actual)    // modifies `actual'
{
    cout << "Saw " << actual << endl;
    bool ret = actual == "hello";
    actual += ".";
    return ret;
}

class X
{
    public:
                            // merely inspects `actual'
        static bool cmp(string const &actual)
        {
            cout << "Saw " << actual << endl;
            return actual == "hello";
        }
};

int main(int argc, char **argv)
{
    vector<string> vs(argv, argv + argc);

    vector<string>::iterator it;

    it = find_if(vs.begin(), vs.end(),
        FnWrap1<string &, bool>(&cmp));

    if (it != vs.end())
        cout << "At " << *it << endl;

    cout << endl;

    it = find_if(vs.begin(), vs.end(),
        FnWrap1<string const &, bool>(&X::cmp));

    if (it != vs.end())
        cout << "At " << *it << endl;

}
