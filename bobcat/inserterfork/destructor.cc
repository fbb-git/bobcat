#include "inserterfork.ih"

InserterFork::~InserterFork()
{
    d_oChildIn.flush();
}
