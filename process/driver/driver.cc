//#ifdef BOBCAT
    #include <bobcat/process>
//#else
//    #include "process"
//#endif

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
    cout << "Size of Process: " << sizeof(Process) << endl;
    string line;

        // Nota bene: without IOMode you get CIN, COUT and CERR
    Process p1(Process::CIN, "/bin/cat"); 
    Process p2(Process::STD, "/bin/cat");
    Process p3(Process::STD, "/bin/cat");


    prompt("sending lines (until empty) to cat | cat | cat");
    (p1 | p2 | p3).start();

    while (getline(cin, line) && not line.empty())
    {
        cout << "Entering " << line << endl;
        p3 << line << endl;
    }

    p3.close();
    p3.waitForChild();

//
//    Process process(Process::CIN | Process::COUT,
//                    "/usr/bin/sha1sum");
//
//    prompt("sha1sum");
//    process.start();
//    process << "Hello world\n";         // input to sha1sum
//    process.close();
//    process >> line;                    // retrieve the value
//    cout << line << endl;
//    process.stop();
//
//    prompt("cat, ignoring its output");
//    process.setCommand("/bin/cat");
//    process.setIOMode(Process::CIN | Process::IGNORE_COUT);
//
//    process.start();
//    process << "Hello world\n";         // input to sha1sum
//    process.close();
//
//    line.clear();
//    if (process >> line)                // retrieve the value
//        cout << ">>>" << line << "<<<" << endl;
//    process.stop();
//
//
////    if (argc > 1)                       // sending an e-mail
////    {
////        cout << "Sending mail to " << argv[1] << endl;
////        prompt("/usr/bin/mail");
////        process.setCommand("/usr/bin/mail -s 'from Process' ");
////        process += argv[1];
////        process.start(Process::CIN);
////        process << "This mail was sent by the process drive\n";
////        process << "It consists of multiple lines of text\n";
////        process.close();
////        process.waitForChild();
////    }
//
//    prompt("5 seconds IO to /bin/cat");
//    process.setIOMode(Process::CIN | Process::COUT);
//    process.setTimeLimit(5);            // change time limit
//
//    process = "/bin/cat";
//    while (process.active())
//    {
//        cout << "? ";
//        getline(cin, line);
//        process << line << endl;        // to /bin/cat
//        line.clear();
//        if (!getline(process, line))    // from /bin/cat
//            break;
//        cout << "Received: " << line << endl;
//    }
//    cout << "/bin/cat forcefully terminated\n";
//
//    process.setTimeLimit(0);
//
//    cout << "3 times running /bin/ls\n";
//
//    for (size_t trial = 0; trial < 3; ++trial)
//    {
//        prompt("ls");
//
//        process(Process::COUT) = "/bin/ls";
//
//        cerr << process.str() << endl;
//        size_t count = 0;
//        while (getline(process, line))
//            cout << ++count << ": " << line << endl;
//   }
//
}
catch (exception const &err)
{
    cerr << "CAUGHT EXCEPTION: " << err.what() << endl;
    return 1;
}
catch (bool)
{
    return 0;
}

catch (...)
{
    cerr << "Unrecognized exception in main()\n";
    return 0;
}
