#include "process.ih"

void Process::collect(vector<string> *collector, int fd)
{
    string line;
    IFdStream ifd(fd, s_bufSize);

    while (getline(ifd, line))
        collector->push_back(line);
}
