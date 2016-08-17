/*
                              driver.cc
*/

#include <bobcat/exception>
#include <bobcat/level>
#include <iostream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    try
    {
        Log::instance() << "hello world" << endl;
    }
    catch(exception const &e)
    {
        cout << e.what() << endl;
    }


    Log log;

    log << ": message to cout" << nl << 
            "<-- No timestamp here " << '\n' <<
            "<-- But timestamp here " << endl;

    Log::instance() << "\n";

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
}
