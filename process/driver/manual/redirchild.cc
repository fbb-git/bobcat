#include "main.hh"

void redirectChild()
{
    d_child_inp->readFrom(STDIN_FILENO);  // set up the pipes
    d_child_outp->writtenBy(STDOUT_FILENO);
}
