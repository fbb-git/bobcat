#include "sharedsegment.ih"

void SharedSegment::rawDetach(void *sharedPtr, bool requireOK)
{
    if (sharedPtr == 0 || shmdt(sharedPtr) == 0)
        return;

    if (requireOK)
        throw Exception() << "Failed to detach shared segment";
}
