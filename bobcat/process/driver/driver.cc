/*
                              driver.cc
*/

#include "driver.h"
#include <algorithm>
#include <iterator>

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    string line;
    Process p;

    cout << "The file `out' is removed, if existing\n";
    cout << "Press enter to do so..." << endl;
    getline(cin, line);

    p = "/bin/rm -f out";

    p.clear();

    cout << "Press enter to continue" << endl;
    getline(cin, line);

    cout << "The output of the command `/bin/ls':\n";
    p = "/bin/ls";
    copy(p.cout().begin(), p.cout().end(), 
                                ostream_iterator<string>(cout, "\n"));


    cout << "Now this output is redirected to a file `out':\n";
    p << " > out";
    
    cout << "The following command will be executed using system():\n"
            "`" << p.str() << "'" << endl;

    p.system();
    copy(p.cout().begin(), p.cout().end(), 
                                ostream_iterator<string>(cout, "\n"));

    cout << "Press enter to continue" << endl;
    getline(cin, line);

    cout << "Enter lines containing arguments. Empty line to quit:\n";

    while (true)
    {
        if (!getline(cin, line) || !line.length())
            break;

        p.clear();
        p << "./echoargs " << line;
        p.execute();

        copy(p.cout().begin(), p.cout().end(), 
                                    ostream_iterator<string>(cout, "\n"));
    }

    return 0;
}
