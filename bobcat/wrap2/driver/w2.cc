#include "../wrap2"

#include <string>

using namespace std;
using namespace FBB;


bool function(string &, string const *);

int main()
{
    Wrap2<string, string, bool> w2(function);

    string one;
    string two;

    w2(one, &two);

}
