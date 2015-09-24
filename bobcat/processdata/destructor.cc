#include "processdata.ih"

ProcessData::~ProcessData()
{
    Signal::instance().remove(SIGCHLD, *this);  
}
