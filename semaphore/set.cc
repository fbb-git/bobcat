#include "semaphore.hh"

void Semaphore::set(size_t available)
{
    lock_guard<mutex> lk(d_mutex);
    d_nAvailable = available;
}
