//#include <bobcat/cininserter>
#include "../cininserter"

#include <iostream>
#include <fstream>

using namespace std;
using namespace FBB;

int main()
{
    CinInserter inserter;

    inserter.execute("/bin/cat");
    ifstream in("build");
    inserter << in.rdbuf();

    cout << "child returns: " << inserter.stop() << '\n';

    inserter.execute("/bin/cat");
    in.seekg(0);                    // reset to the beginning
    inserter << in.rdbuf();

    // when immediately followed by another execute, 'stop' is optional

    inserter.execute("/bin/cat", "a simple text\n");
    inserter.execute("/bin/cat", "a simple text\n");
    bool bret = inserter.execute("/bin/cat", "a simple text\n");

    cout << "direct string insertion: " << bret << '\n';
}
