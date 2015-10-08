#include "main.ih"

void childSha1()
{
    char *args[] = {const_cast<char *>("/usr//bin/sha1sum"), 0};
    execv(args[0], args);

    std::cerr << "CHILD FORK FAILED\n";
}
