/*
                              driver.cc
*/

#include <bobcat/errno>
#include <bobcat/level>
#include <iostream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv, char **envp)
{
    try
    {
        Log::getInstance() << "hello world" << endl;
    }
    catch(Errno const &e)
    {
        cout << e.what() << endl;
    }


    Log log(STATIC);

    log << ": message to cout" << nl << 
            "<-- No timestamp here " << '\n' <<
            "<-- But timestamp here " << endl;

    Log::getInstance() << "\n";

    log.setLevel(1);
    log.setTimestamp(NOTIMESTAMPS);

    log.level(0) << "Not shown" << "\n";

    log.level(1) << "Shown" << "\n";
    log << "This one too" << endl;
    

    log << level(0) << "Again not shown\n";
    log << level(1) << "Shown again\n";

    log.setLevel(5);

    log << level(1) << "Not shown\n";
    log << level(5) << "Shown again\n";

    return 0;
}

