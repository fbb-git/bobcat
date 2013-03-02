#include <iostream>
#include <iterator>

#include <bobcat/errno>
#include "../configfile"

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
                    ConfigFile::SearchCaseInsensitive, 
                    ConfigFile::StoreIndices);

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
    cout << cf[0] << " from line " << cf.index(0) << "\n";
    cout << "================\n";

    copy(cf.begin(), cf.end(), ostream_iterator<string>(cout, "\n"));
    
    while (true)
    {
        cerr << "Literal search for: \n";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        vector<string>::const_iterator it = cf.find(param);

        if (it != cf.end())
            cout << *it << ": at index " << cf.index(it) << endl;
        else        
            cout << " < not found > " << endl;
    }
    
    while (true)
    {
        cerr << "RE search for: \n";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        vector<string>::const_iterator it = cf.findRE(param);

        if (it != cf.end())
            cout << *it << ": at index " << cf.index(it) << endl;
        else        
            cout << " < not found > " << endl;
    }
    
    return 0;
}
