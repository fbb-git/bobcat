#include "spawn.ih"

//  1: program[0]
//  2: command
//  3: cin-name
//  4: cout-name
//  5: cerr-name

Spawn::Spawn(std::string const &command)
:
    d_command(command),
    d_insertBuffer(d_insertPipe.writeFd(), 10000)

//    d_extractBuffer(d_extractPipe.readOnly()),
//    d_errStream(d_errPipe.readOnly())
{
    rdbuf(&d_insertBuffer);
//    rdbuf(&d_extractBuffer);
}

