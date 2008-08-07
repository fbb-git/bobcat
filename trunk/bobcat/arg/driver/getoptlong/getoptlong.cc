#include "getoptlong.h"

#include <cstdlib>
#include <getopt.h>

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    int value;

    opterr = 0;

    struct option longopts [] =
    {
        {"a-opt", 0, 0, 'a'},
        {"one", 0, &value, 100},
        {"two", 0, &value, 200},
        {0, }
    };

    while (true)
    {
        int c = getopt_long(argc, argv, "abc", longopts, 0);
        char ch = c;
        char co = optopt;

        switch (c)
        {
            case EOF:
                cout << "All processed\n";
            return 0;

            case ':':
                cout << "ArgData::ArgData(): missing option value" << endl;
            break;

            case '?':
                cout << "ArgData::ArgData(): unknown option"  <<
                                optopt << " (" << co << ")" << endl;
            break;

            case 0:
                cout << "0 return. val = " << value << endl;
            break;

            default:
                cout << "Default return. c = " << ch << ", optopt = " <<
                                    optopt << endl;
            break;    
        }
    }
}



