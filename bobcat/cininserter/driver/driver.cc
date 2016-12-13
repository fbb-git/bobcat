#include <bobcat/cininserter>

#include <iostream>
#include <fstream>

using namespace std;
using namespace FBB;

void insert(CinInserter &inserter)
{
    ifstream in("driver.cc");
    inserter << in.rdbuf();
    inserter.stop();
}
    
int main()
{
    CinInserter inserter;

    bool bret = inserter.execute("/bin/cat",    // copies to stdout
        [](CinInserter &inserter)
        {
            insert(inserter);
        }
    );

    int ret = inserter.ret();

    cout << "Returning: " << bret << ' ' << ret << "\n"
            "again:\n";

    bret = inserter.execute("/bin/cat",         
        [](CinInserter &inserter)
        {
            insert(inserter);
        }
    );

    ret = inserter.ret();

    cout << "Returning: " << bret << ' ' << ret << '\n';
}



