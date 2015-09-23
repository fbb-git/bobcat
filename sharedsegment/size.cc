#include "sharedsegment.hh"

size_t SharedSegment::size(int id) 
{
    struct shmid_ds buf;

    if (shmctl(id, IPC_STAT, &buf) == -1)
        throw Exception() << "Can't determine segment size of segment " << 
                            id << ": " << errnodescr;

    return buf.shm_segsz;
}
