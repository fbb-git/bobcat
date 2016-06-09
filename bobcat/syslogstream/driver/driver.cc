/*
                              driver.cc
*/

#include <bobcat/syslogstream>
#include <iostream>

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
{
    Syslogbuf sbuf(argv[0]);        // via a separate Syslogbuf

    ostream sls(0);
    sls.rdbuf(&sbuf);

//    SyslogStream sls(argv[0]);      // via an explicit SyslogStream

    sls << SyslogStream::notice << "Hello world" << endl;
}




