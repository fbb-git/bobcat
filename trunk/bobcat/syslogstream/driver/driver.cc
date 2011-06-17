/*
                              driver.cc
*/

#include <bobcat/syslogstream>
#include <iostream>

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    SyslogStream sls(argv[0]);

    sls << SyslogStream::debug << "Hello world" << endl;

    return 0;
}




