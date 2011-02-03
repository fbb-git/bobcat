/*
                              driver.cc
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <bobcat/errno>

#ifdef BOBCAT
    #include <bobcat/arg>
#else
    #include "arg"
#endif

using namespace std;
using namespace FBB;

void optcheck(char c)
{
    Arg &arg = Arg::instance();

    if (size_t count = arg.option(c))
        cout << "Saw option " << c << " " << count << " times" << '\n';

    if (string("def").find(c) != string::npos)
    {
        string value;
        size_t idx;

        idx = arg.option(&value, c);
        cout << idx << " returned by option() for "
                        "option " << c << 
                        ", which has value `" << value << "'\n";

        size_t count = arg.option(&idx, &value, c);
        cout << count << " times option " << c << '\n';
        if (idx == count)
            cout << "No non-empty option values" << '\n';
        else
        {
            cout << "First non-empty option at " << idx << '\n';
            for (size_t ix = 0; ix < count; ++ix)
            {
                arg.option(ix, &value, c);
                cout << ix << ": " << value << '\n';
            }
        }
    }
    cout << '\n';
}

void longopt(char const *longOpt)
{
    string value;
    Arg &arg = Arg::instance();

    size_t opt =  arg.option(&value, longOpt);
    if (!opt)
        return;

    cout << longOpt << " " << opt << " times:\t" <<
                (value.length() ? value : "-- no arg--") << '\n';
}


void usage(string  const  &progname)
{
    cout <<     
        "Usage: " << progname << " arg options\n"
        "where:\n"
        "   arg: any argument\n"
        "   options: any option from abcd:e:f:hv\n"
        "            try options requiring arguments without specifying an "
                                                                "argument\n"
        "            try other options too. -h provides this help,\n"
        "            -v provides the version\n"
        "Available long options:\n"
        "    --optional, --extra (+ arg), --file (as -f),\n"
        "    --version (as -v), --add (as -a)\n";
}

namespace {
}

int main(int argc, char **argv)
try
{
    Arg::LongOption lo[] =
    {
        {"optional", Arg::Optional},
        {"extra", Arg::Required},
        {"file", 'f'},
        {"version", 'v'},
        {"add", 'a'}
    };
    try
    {    
        Arg::initialize("abcd:e:f:hv", 
                lo, lo + 5,
                argc, argv);

        Arg &arg = Arg::instance();

        arg.versionHelp(usage, "0.00", 1);

        for_each("abcdefg", "abcdefg" + 7, optcheck)
            ;

        for (size_t idx = 0; idx < arg.nArgs(); idx++)
            cout << "Argument " << idx << " = " << arg[idx] << '\n';
        cout << '\n';

        cout << "Long options:\n" << dec;
        longopt("optional");
        longopt("extra");
        longopt("file");
        longopt("add");
    }
    catch (Errno const &e)
    {
        cout << e.which() << " " << e.why() << '\n';
    }

}

catch (int x)
{
    cout << "int exception caught, value = " << x << '\n';
    return x;
}
catch (Errno const &e)
{
    cout << "Errno exception caught, why() = " << e.why() << "\n"
            "which() is: " << e.which() << '\n';

    return e.which();
}
catch (...)
{
    cout << "Unexpected exception caught, shouldn't happen\n";
    return 1;
}
