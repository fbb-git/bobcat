#include "sharedmutex.ih"

SharedMutex::~SharedMutex()
{
    unlock();
}
