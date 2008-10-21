#include <iostream>
#include <string>
#include "../process"

using namespace std;
using namespace FBB;

int main()
try
{
    string line;

     Process process;


     process(1, Process::COUT) = "/bin/ls";

     size_t count = 0;
     while (getline(process, line))
         cout << ++count << ' ' << line << endl;

     process(1, Process::COUT | Process::IGNORE_CERR) 
         = "`/bin/ls -Fla driver.cc`";         // stop the existing command,
                                         // start another command
                                         // (assignment implies
                                         // `stop()')
 
     while (getline(process, line))      // read all its output
         cout << line << endl;
 

//    process(Process::CIN) = "./a.out";
//    process << endl;

    try
    {
        while (true)
        {
             process(Process::CIN | Process::COUT) = "/bin/cat";
    
             while (true)
             {
                cout << "r restarts, empty quits ? ";
 
                if (!getline(cin, line) || line.empty())
                    throw false;

                if (line == "r")
                    break;
 
                if (!process.verify())
                    break;

                process << line << endl;
                cout << "To the child: " << line << endl;

                line.erase();

                getline(process, line);
                cout << "Received fm the child: " << line << endl;
            }
        }
    }
    catch (bool)
    {
        cout << "/bin/cat ended\n";
    }

     process(Process::CIN | Process::COUT | Process::IGNORE_CERR)
            = "/usr/bin/sha1sum";
 
     cout << "Command to execute: " << process.str() << endl;
 
    process << "hello world" << endl;   // insert this text
    process.close();
 
    getline(process, line);             // read its output
    cout << line << endl;               // show it

    cout << "sending mail to myself\n";

    process(Process::CIN) = "/usr/bin/mail -s 'to myself' frank@localhost";

    process << "Hello world" << endl;
    process.close();

    cout << "closed\n";
    process.waitForChild();
    cout << "done\n";


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






