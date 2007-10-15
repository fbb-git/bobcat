#include <iostream>
#include <string>
#include <bobcat/process>

using namespace std;
using namespace FBB;

int main()
{
    string line;
                                        // setup a command
    Process process("/bin/cat", Process::CIN |
                                Process::COUT |
                                Process::IGNORE_CERR);

    process.start();                    // start it

    process << "hello world" << endl;   // insert this text
    getline(process, line);             // read its `cat' output
    cout << line << endl;               // show it

    process = "`/bin/ls`";              // stop the existing command,
                                        // start another command
                                        // (assignment implies
                                        // `stop()')

    while (getline(process, line))      // read all its output
        cout << line << endl;

    cout << process.stop() << endl;     // show the process' exit
                                        // value
    return 0;
}

