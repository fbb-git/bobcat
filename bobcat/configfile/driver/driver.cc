#ifndef _INCLUDED_DRIVER_CC_
#define _INCLUDED_DRIVER_CC_

#include <iostream>
#include <iterator>

#include <bobcat/errno>
#include "../configfile.h"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Need name of configfile\n";
        return 1;
    }

    ConfigFile cf(ConfigFile::RemoveComment, 
                    ConfigFile::SearchCaseInsensitive);

    try 
    {
        cf.open(argv[1]);
    }
    catch (Errno e)
    {
        cout << "Fatal: " << e.what() << endl;
        return 1;
    }

    cout << "Got " << cf.size() << " lines\n";
    cout << cf[0] << "\n";
    cout << cf[0] << "\n";
    cout << "================\n";

    copy(cf.begin(), cf.end(), ostream_iterator<string>(cout, "\n"));
    
    while (true)
    {
        cerr << "Literal search for: \n";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        vector<string>::const_iterator it = cf.find(param);

        cout << (it != cf.end() ? *it : " < not found > ") << endl;
    }
    
    while (true)
    {
        cerr << "RE search for: \n";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        vector<string>::const_iterator it = cf.findRE(param);

        cout << (it != cf.end() ? *it : " < not found > ") << endl;
    }
    
    return 0;
}




#endif
