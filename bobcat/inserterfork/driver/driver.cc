#include "../inserterfork"

#include <iostream>
#include <fstream>

using namespace std;
using namespace FBB;

void insert(InserterFork &inserter)
{
    ifstream in("driver.cc");
    inserter << in.rdbuf();
    inserter.stop();
}
    
int main()
{
    InserterFork inserter;

    bool bret = inserter.execute("/bin/cat",    // copies to stdout
        [](InserterFork &inserter)
        {
            insert(inserter);
        }
    );

    int ret = inserter.ret();

    cout << "Returning: " << bret << ' ' << ret << "\n"
            "again:\n";

    bret = inserter.execute("/bin/cat",         
        [](InserterFork &inserter)
        {
            insert(inserter);
        }
    );

    ret = inserter.ret();

    cout << "Returning: " << bret << ' ' << ret << '\n';
}



