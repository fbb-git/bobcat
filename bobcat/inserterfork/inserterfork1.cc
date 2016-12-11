#include "inserterfork.ih"

InserterFork::InserterFork(size_t bufSize)
:
    ostream(this),
    d_bufSize(bufSize)
{}

