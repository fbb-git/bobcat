/*
                              driver.cc
*/

#include "driver.h"

#include <algorithm>
#include <bobcat/errno>

#include "../arg"

using namespace std;
using namespace FBB;

void optcheck(char c)
{
    Arg &arg = Arg::instance();

    if (size_t count = arg.option(c))
        cout << "Saw option " << c << " " << count << " times" << endl;

    if (string("def").find(c) != string::npos)
    {
        string value;
        size_t idx;

        arg.option(&value, c);
        cout << "First option value of " << c << " is " << value << endl;

        size_t count = arg.option(&idx, &value, c);
        cout << count << " times option " << c << endl;
        if (idx == count)
            cout << "No non-empty option values" << endl;
        else
        {
            cout << "First non-empty option at " << idx << endl;
            for (size_t ix = 0; ix < count; ++ix)
            {
                arg.option(ix, &value, c);
                cout << ix << ": " << value << endl;
            }
        }

    }
}

void longopt(char const *longOpt)
{
    string value;
    Arg &arg = Arg::instance();

    size_t opt =  arg.option(&value, longOpt);
    if (!opt)
        return;

    cout << longOpt << " " << opt << " times:\t" <<
                (value.length() ? value : "-- no arg--") << endl;
}

int main(int argc, char **argv)
{
    Arg::LongOption lo[] =
    {
        Arg::LongOption("optional", Arg::Optional),
        Arg::LongOption("extra", Arg::Required),
        Arg::LongOption("file", 'f'),
        Arg::LongOption("version"),
        Arg::LongOption("add", 'a')
    };
    try
    {    
        Arg::initialize("abcd:e:f:", 
                lo, lo + 5,
                argc, argv);
    
        Arg &arg = Arg::getInstance();

        cout << "Program name is " << arg.basename() << endl;
    
        for_each("abcdefg", "abcdefg" + 7, optcheck)
            ;

        for (size_t idx = 0; idx < arg.nArgs(); idx++)
            cout << "Argument " << idx << " = " << arg[idx] << endl;

        cout << "Long options:\n" << dec;

        longopt("optional");
        longopt("extra");
        longopt("file");
        longopt("version");
        longopt("add");

    }
    catch (Errno const &e)
    {
        cout << e.which() << " " << e.what() << endl;
    }

    return 0;
}
