#include "sharedmutex.hh"

SharedMutex::~SharedMutex()
{
    unlock();
}
