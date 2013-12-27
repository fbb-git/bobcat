#include <iostream>
#include "../process"
//#include <bobcat/process>

using namespace std;
using namespace FBB;

int main()
{
        // Nota bene: without IOMode you get CIN, COUT and CERR
    Process p1(Process::CIN, "/bin/cat"); 
    Process p2(Process::STD, "/bin/cat");
    Process p3(Process::STD, "/bin/cat");

    (p1 | p2 | p3).start();

    p3 << cin.rdbuf() << eoi;
}
    





