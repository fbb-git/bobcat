#include <iostream>

#include "../../processenums/processenums"
#include "../../processdata/processdata.decl"
#include "../process"

using namespace std;
using namespace FBB;

//CODE
int main()
{
    Process process(Process::COUT, "/bin/ls -Fla");

    process.start();
    cout << process.childOutStream().rdbuf();
}
//=

