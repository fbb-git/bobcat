#include "../process"
#include <string>
#include <iostream>

using namespace std;
using namespace FBB;

void prompt(char const *task)
{
    cout << "Press Enter to start " << task << endl;
    cin.ignore(INT_MAX, '\n');
}

int main()
try
{
    string line;

    Process process(Process::COUT | Process::CIN, "/usr//bin/sha1sum");

    prompt("sha1sum");
    
    process.start();

    process << "Hello world\n";
    process.close();

    while (getline(process, line))
        cout << line << endl;

    process.stop();

    prompt("10 seconds /bin/cat");

    process(10, Process::CIN | Process::COUT) = "/bin/cat";

    cout << "/bin/cat/started\n";
    getline(cin, line);

    while (process.verify())
    {
        cout << "? ";
        getline(cin, line);
        process << line << endl;
        line.clear();
        getline(process, line);
        cout << "Received: " << line << endl;
    }


    for (size_t trial = 0; trial < 5; ++trial)
    {
        prompt("ls");

        process(0, Process::CIN | Process::COUT) = "/bin/ls";

        cerr << process.str() << endl;
        size_t count = 0;
        while (getline(process, line))
            cout << ++count << ": " << line << endl;
    }
}
catch (Errno const &err)
{
    cerr << err.what() << endl;
    return 1;
}
catch (Process::TimeOut)
{
    return 0;   // monitor times out
}
catch (...)
{
    cerr << "Unrecognized exception in main()\n";
    return 0;
}
