#include "../wrap2c"

#include <string>

using namespace std;
using namespace FBB;


struct Context
{
    size_t x;
};

bool function(string &, string *, Context const *);

int main()
{
    Context context = {12};

    Wrap2c<string, string, Context, bool> w2c(function, &context);

    string one;
    string two;

    w2c(one, &two);

}
