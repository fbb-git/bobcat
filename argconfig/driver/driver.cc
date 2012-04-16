#include <iostream>
#include <string>

#include "argconfig"

using namespace std;
using namespace FBB;

namespace 
{
    ArgConfig::LongOption lo[] =
    {
        ArgConfig::LongOption("option", 'o'),
        ArgConfig::LongOption("option-value", 'v')
    };
}

class X
{
    ArgConfig &d_arg;

    public:
        X();
        void function();
};

X::X()
:
    d_arg(ArgConfig::instance())
{}

void X::function()
{
    if (d_arg.nArgs() == 0)
        throw Errno("Provide the name of a config file as 1st arg");

    cout << "Counting " << d_arg.option('o') << " instances of -o or "
                                                            "--option\n";

    cerr << "\nNow opening config file `" << d_arg[0] << "'\n";

    d_arg.open(d_arg[0]);       // Now open the config file explicitly
                            // (alternatively: use a constructor expecting 
                            // a file name)

    cout << "Counting " << d_arg.option('o') << " instances of -o or "
                                                            "--option\n";

    string optval;
    size_t count = d_arg.option(&optval, 'v');

    cout << "Counting " << count << 
                        " instances of -v or --option-value\n";
}

int main(int argc, char **argv)
try
{
    ArgConfig::initialize("ov:", lo, lo + 2, argc, argv);

    X x;
    x.function();
}
catch (Errno const &err)
{
    cout << "Terminating " << err.why() << endl;
    return 1;
}



