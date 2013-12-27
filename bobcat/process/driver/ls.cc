#include <iostream>
#include "../process"

using namespace std;
using namespace FBB;

int main()
{
    Process process("/bin/ls -Fla");
    process.setIOMode(Process::COUT);

    process.start();
    cout << process.childOutStream().rdbuf();
}
    
