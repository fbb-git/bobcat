#include "main.hh"

void childLs()
{
    char *args[] = {const_cast<char *>("/bin/ls"), 0};
    execv(args[0], args);

    std::cerr << "CHILD FORK FAILED\n";
}
