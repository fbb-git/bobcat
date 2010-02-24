#include <bobcat/process>
#include <string>
#include <iostream>
#include <climits>

using namespace std;
using namespace FBB;

void prompt(char const *task)
{
    cout << "Press Enter to start " << task << endl;
    cin.ignore(INT_MAX, '\n');
}

int main(int argc, char **argv)
try
{
    string line;
    Process process(Process::CIN | Process::COUT,
                    "/usr/bin/sha1sum");

    prompt("sha1sum");
    process.start();
    process << "Hello world\n";         // input to sha1sum
    process.close();
    process >> line;                    // retrieve the value
    cout << line << endl;
    process.stop();

    if (argc > 1)                       // sending an e-mail
    {
        cout << "Sending mail to " << argv[1] << endl;
        prompt("/usr/bin/mail");
        process.setCommand("/usr/bin/mail -s 'from Process' ");
        process += argv[1];
        process.start(Process::CIN);
        process << "This mail was sent by the process drive\n";
        process << "It consists of multiple lines of text\n";
        process.close();
        process.waitForChild();
    }

    prompt("5 seconds IO to /bin/cat");
    process.setTimeLimit(5);            // change time limit
    process = "/bin/cat";
    while (process.active())
    {
        cout << "? ";
        getline(cin, line);
        process << line << endl;        // to /bin/cat
        line.clear();
        if (!getline(process, line))    // from /bin/cat
            break;
        cout << "Received: " << line << endl;
    }
    cout << "/bin/cat forcefully terminated\n";

    process.setTimeLimit(0);
    for (size_t trial = 0; trial < 5; ++trial)
    {
        prompt("ls");

        process(Process::COUT) = "/bin/ls";

        cerr << process.str() << endl;
        size_t count = 0;
        while (getline(process, line))
            cout << ++count << ": " << line << endl;
    }
}
catch (Errno const &err)
{
    cerr << "EXCEPTION CAUGHT: " << err.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Unrecognized exception in main()\n";
    return 0;
}
