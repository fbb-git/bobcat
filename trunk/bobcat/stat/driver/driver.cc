/*
                              driver.cc
*/

#include <iostream>
#include <string>

#include <bobcat/stat>
#include <bobcat/datetime>

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    if (argc == 1)
    {
        cout << "Directory entry required\n";
        return 1;
    }

    Stat st;
    if (argc == 2)
        st.set(argv[1]);
    else if (argc == 3)
        st.set(argv[1], argv[2]);

    if (!st)
    {
        cout << "Can't stat " << argv[1] << ", errno = " << st.error() << endl;
        return 1;
    }

    cout << st.name() << ": access: " << st.lastAccess() << endl;
    cout << st.name() << ": change: " << st.lastChange() << endl;
    cout << st.name() << ": modif:  " << st.lastModification() << endl;
    cout << "Mode: " << oct << st.mode() << endl;
    cout << "Type: " << st.type() << endl;
    switch (st.type())
    {
        case Stat::REGULAR_FILE:
            cout << "It's a regular file\n";
        break;
        case Stat::DIRECTORY:
            cout << "It's a directoryregular file\n";
        break;
        default:
            cout << "It's not a directory nor regular file\n";
        break;
    }

    cout << "Full path:  " << st.path()  << endl;
    return 0;
}

