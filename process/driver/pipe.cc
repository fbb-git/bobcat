#include <iostream>

#include "../../processenums/processenums"
#include "../../processdata/processdata.decl"
#include "../process"

using namespace std;
using namespace FBB;

int main()
{
    // Nota bene: by default IOMode equals Process::ALL

    Process p1(Process::CIN, "/bin/cat"); 
    Process p2(Process::STD, "/bin/cat");
    Process p3(Process::STD, "/bin/cat");

    (p1 | p2 | p3).start();

    p3 << cin.rdbuf() << eoi;
}
    





