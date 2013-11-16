#include "sharedsegment.ih"

void SharedSegment::deleteSegment(int id)
{
    struct shmid_ds buf;

    if (shmctl(id, IPC_RMID, &buf) != 0)
        throw Exception() << "Could not discard shared segment " << id;
}
