#include <iostream>
#include "../process"
//#include <bobcat/process>

using namespace std;
using namespace FBB;

//CODE
int main()
{
    Process process(Process::CIN | Process::COUT, "/bin/cat");
    process.setTimeLimit(5);

    process.start();

    while (true)
    {
        cout << "? ";
        string line;
        if (not getline(cin, line))
            return 0;

        process << line << endl;        // to /bin/cat
        line.clear();

        if (not getline(process, line))    // from /bin/cat
            break;

        cout << "Received: " << line << endl;
    }

    cout << "/bin/cat time limit of 5 seconds reached: child process ended\n";
}
//=






