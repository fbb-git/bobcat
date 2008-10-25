/*
                              driver.cc
*/

#include "driver.h"

#include <algorithm>
#include <bobcat/errno>

#include "../argconfig"

using namespace std;
using namespace FBB;

void optcheck(char c)
{
    ArgConfig &argconfig = ArgConfig::instance();

    if (size_t count = argconfig.option(c))
        cout << "Saw option " << c << " " << count << " times" << endl;

    if (string("def").find(c) != string::npos)
    {
        string value;
        size_t idx;

        idx = argconfig.option(&value, c);
        cout << idx << " returned by option() for "
                        "option " << c << 
                        ", which has value `" << value << "'\n";

        size_t count = argconfig.option(&idx, &value, c);
        cout << count << " times option " << c << endl;
        if (idx == count)
            cout << "No non-empty option values" << endl;
        else
        {
            cout << "First non-empty option at " << idx << endl;
            for (size_t ix = 0; ix < count; ++ix)
            {
                argconfig.option(ix, &value, c);
                cout << ix << ": " << value << endl;
            }
        }
    }
    cout << endl;
}

void longopt(char const *longOpt)
{
    string value;
    ArgConfig &argconfig = ArgConfig::instance();

    size_t opt =  argconfig.option(&value, longOpt);
    if (!opt)
        return;

    cout << longOpt << " " << opt << " times:\t" <<
                (value.length() ? value : "-- no argconfig--") << endl;
}


void usage(string  const  &progname)
{
    cout <<     
        "Usage: " << progname << " argconfig options\n"
        "where:\n"
        "   argconfig: any argconfigument\n"
        "   options: any option from abcd:e:f:hv\n"
        "            try options requiring argconfiguments without specifying an "
                                                                "argconfigument\n"
        "            try other options too. -h provides this help,\n"
        "            -v provides the version\n"
        "Available long options:\n"
        "    --optional, --extra (+ argconfig), --file (as -f),\n"
        "    --version (as -v), --add (as -a)\n";
}

 
int main(int argconfigc, char **argconfigv)
try
{
    ArgConfig::LongOption lo[] =
    {
        ArgConfig::LongOption("optional", ArgConfig::Optional),
        ArgConfig::LongOption("extra", ArgConfig::Required),
        ArgConfig::LongOption("file", 'f'),
        ArgConfig::LongOption("version", 'v'),
        ArgConfig::LongOption("add", 'a')
    };
    try
    {    
        ArgConfig::initialize("abcd:e:f:hv", 
                lo, lo + 5,
                argconfigc, argconfigv);

        ArgConfig &argconfig = ArgConfig::getInstance();

        argconfig.versionHelp(usage, "0.00", 1);

        for_each("abcdefg", "abcdefg" + 7, optcheck)
            ;

        for (size_t idx = 0; idx < argconfig.nArgConfigs(); idx++)
            cout << "ArgConfigument " << idx << " = " << argconfig[idx] << endl;
        cout << endl;

        cout << "Long options:\n" << dec;
        longopt("optional");
        longopt("extra");
        longopt("file");
        longopt("add");
    }
    catch (Errno const &e)
    {
        cout << e.which() << " " << e.what() << endl;
    }

    return 0;
}
catch (int x)
{
    cout << "int exception caught, value = " << x << endl;
    return x;
}
catch (Errno const &e)
{
    cout << "Errno exception caught, what() = " << e.what() << "\n"
            "which() is: " << e.which() << endl;

    return e.which();
}
catch (...)
{
    cout << "Unexpected exception caught, shouldn't happen\n";
    return 1;
}
