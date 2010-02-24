#include <iostream>
#include <iomanip>

#include <bobcat/log>

using namespace std;
using namespace FBB;

int main()
{
    Log &log = Log::initialize("&1");

    log << "This message is written to cout" << nl <<
           setw(16) << ' ' << "occupying multiple lines\n";

    log.off();
    log << "This message is not shown\n";
    log.setLevel(0);
    log << "This message is shown again\n";
    return 0;
}
