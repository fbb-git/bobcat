#include <iostream>
#include <string>
#include "../process"

using namespace std;
using namespace FBB;

int main()
{
    string line;

                                        // setup a command
    Process process("/usr/bin/sha1sum -", Process::CIN |
                                Process::COUT |
                                Process::IGNORE_CERR);

    process.start();                    // start it

    process << "hello world" << endl;   // insert this text
//    process.close();

    getline(process, line);             // read its `cat' output
    cout << line << endl;               // show it

//    process = "`/bin/ls`";              // stop the existing command,
//                                        // start another command
//                                        // (assignment implies
//                                        // `stop()')
//
//    while (getline(process, line))      // read all its output
//        cout << line << endl;
//
//    cout << process.stop() << endl;     // show the process' exit
//                                        // value
    return 0;
}

