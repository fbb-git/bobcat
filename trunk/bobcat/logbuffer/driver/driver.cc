#include <iostream>
#include <iomanip>

#include <bobcat/log>

using namespace std;
using namespace FBB;

int main()
{
    LogBuffer buffer(cout);
    ostream log(&buffer);

    log << "This message is written to cout" << nl <<
           setw(16) << ' ' << "occupying multiple lines\n";

    return 0;
}
