#include "processdata.hh"

ProcessData::~ProcessData()
{
    Signal::instance().remove(SIGCHLD, *this);  
}
