#include <iostream>
#include <string>
#include "../process"

using namespace std;
using namespace FBB;

int main()
{
    string line;

    Process process;

//                                        // example waiting for input()
//    process = "/bin/cat";
//    process.start(Process::COUT | Process::IGNORE_CERR);
//
//    cout << "Press Enter ";
//    getline(cin, line);
//    cout << "You entered: " << line << endl;
//
//    process << endl;
//
//    process.wait(5);                    // at most for 5 seconds


                                        // setup a command
    process = "/usr/bin/sha1sum -";

    cout << "Command to execute: " << process.str() << endl;

    process.start(Process::CIN |        // start it
                  Process::COUT |
                  Process::IGNORE_CERR);

    process << "hello world" << endl;   // insert this text
    process.close();

    getline(process, line);             // read its `cat' output
    cout << line << endl;               // show it

    process = "`/bin/ls`";              // stop the existing command,
                                        // start another command
                                        // (assignment implies
                                        // `stop()')

    process.start(Process::COUT | Process::IGNORE_CERR);
    while (getline(process, line))      // read all its output
        cout << line << endl;

                                        // example using system()
    process = "/bin/ls -Fla /usr/bin > out";
    process.system();
    process.wait();

    cout << process.stop() << endl;     // show the process' exit
                                        // value

    return 0;
}

