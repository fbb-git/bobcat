#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <iostream>
#include <bobcat/ofdstream>
#include <bobcat/ifdstream>
#include <bobcat/pipe>

using namespace FBB;
using namespace std;

int main ()
{
    pid_t pid;
    Pipe pin;
    Pipe pout;

    pin.verify();
    pout.verify();

    pid = vfork();
    if (pid == (pid_t) 0)
    {
        pin.readFrom(STDIN_FILENO);
        pout.writtenBy(STDOUT_FILENO);

        execl("/usr/bin/sha1sum", "sha1sum", 0);

        perror("exec prog1");
        return 1;
    }
    else
    {
        close(pout.writeFd());

        close(pin.readFd());
        OFdStream out(pin.writeFd());

        out << "These are the data" << endl;

        close(pin.writeFd());

        IFdStream in(pout.readFd());
        string line;
        while (getline(in, line))
            cerr << line << endl;


        waitpid(pid, NULL, 0);
        close(pout.readFd());
        return 0;
    }
}




