// Compile as, e.g., 
//
//          g++ --std=c++11  -o run callgenall.cc -lbobcat
//
// Run as, e.g.,
//          run './genall 3' < genall.cc

#include <iostream>
#include <bobcat/process>

using namespace FBB;
using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "provide the path to the program to start as child process\n"
                "provide input to that program on cin\n";

        return 0;
    }

    Process genall(argv[1]);
    genall.start();

    genall << cin.rdbuf();
    genall.close();

    cout << "Standard output:\n" <<
            genall.rdbuf() << "\n"
            "Standard error:\n" << 
            genall.cerr().rdbuf() << '\n';

    genall.waitForChild();
}
