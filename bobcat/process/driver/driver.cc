#include <iostream>
#include <string>
#include "../process"

using namespace std;
using namespace FBB;

int main()
try
{
    string line;

     Process process;       // define (as yet unused) streams

//     process = "/bin/ls";
//
//    size_t count = 0;
//    while (getline(process, line))
//        cout << ++count << ' ' << line << endl;



// 
//     process(Process::COUT | Process::IGNORE_CERR) 
//         = "`/bin/ls -Fla driver.cc`";         // stop the existing command,
//                                         // start another command
//                                         // (assignment implies
//                                         // `stop()')
// 
//     while (getline(process, line))      // read all its output
//         cout << line << endl;
// 

     process(5, Process::CIN | Process::COUT) = "/bin/cat";
     cout << "5 secs interaction\n";

     while (true)
     {
         cout << "? ";
 
         if (!getline(cin, line) || line.empty())
             break;
 
        if (!process.verify())
            break;

        process << line << endl;
        cout << "To the child: " << line << endl;

        line.erase();

        getline(process, line);
        cout << "Received fm the child: " << line << endl;
     }

     process(Process::CIN | Process::COUT | Process::IGNORE_CERR)
            = "/usr/bin/sha1sum";
 
     cout << "Command to execute: " << process.str() << endl;
 
    process << "hello world" << endl;   // insert this text
    process.close();
 
    getline(process, line);             // read its output
    cout << line << endl;               // show it

// 
//                                         // example using system()
// //    process = "/bin/ls -Fla /usr/bin > out";
// //    process.system();
// ////    process.wait();
// //
// //    cout << process.stop() << endl;     // show the process' exit
//                                         // value
// 
    return 0;
}
catch (Process::TimeOut)
{
    return 0;
}
catch (Errno const &err)
{
    cerr << err.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Unrecognized exception in main()\n";
    return 0;
}






