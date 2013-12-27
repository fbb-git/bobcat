#include <iostream>
#include "../process"
//#include <bobcat/process>

using namespace std;
using namespace FBB;

int main()
{
    Process process("/bin/cat");
    process.setIOMode(Process::CIN | Process::COUT);
    process.setTimeLimit(3);

    process.start();

    while (true)
    {
        cout << "? " << flush;
        string line;
        if (not getline(cin, line))
            return 0;

        process << line << endl;        // to /bin/cat
        line.clear();

        if (not getline(process, line))    // from /bin/cat
            break;

        cout << "Received: " << line << endl;
    }

    cout << "/bin/cat time limit of 3 seconds reached: child process ended\n";
}
    





