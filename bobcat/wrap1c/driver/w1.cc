#include "../wrap1c"

#include <string>

using namespace std;
using namespace FBB;


struct Context
{
    size_t x;
};

bool function(string *, Context const *);

int main()
{
    Context context = {12};

    Wrap1c<string, Context, bool> w2c(function, &context);

    string one;

    w2c(&one);

}
