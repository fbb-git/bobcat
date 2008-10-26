/*
                              driver.cc
*/

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
        ArgConfig::LongOption("value-option", 'v')
    };
}

int main(int argc, char **argv)
try
{
    ArgConfig::initialize("ov:", lo, lo + 2, argc, argv);

    ArgConfig &arg = ArgConfig::instance();

    if (arg.nArgs() == 0)
        throw Errno("Provide the name of a config file as 1st arg");

    cout << "Counting " << arg.option('o') << " instances of -o or "
                                                            "--option\n";

    arg.open(arg[0]);       // Now open the config file explicitly
                            // (alternatively: use a constructor expecting 
                            // a file name)

    cout << "Counting " << arg.option('o') << " instances of -o or "
                                                            "--option\n";

    string optval;
    size_t count = arg.option(&optval, 'v');

    cout << "Counting " << count << 
                        " instances of -v or --value-option\n";
    if (count)
        cout << "Option value = " << optval << endl;

    return 0;
}
catch (Errno const &err)
{
    cout << "Terminating " << err.what() << endl;
    return 1;
}
