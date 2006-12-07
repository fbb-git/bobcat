/*
                              driver.cc
*/

#include <iostream>
#include <bobcat/redirector>

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    Redirector redirector(Redirector::STDOUT);
    redirector.swallow(Redirector::STDERR);

    cerr << "This appears at the standard output stream\n"
            "use `a.out > /dev/null' to suppress this message" << endl;

    return 0;
}
