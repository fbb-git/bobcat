#include "sharedcondition.hh"

SharedCondition::SharedCondition(SharedMemory &shmem, std::streamsize offset)
:
    d_shmem(&shmem),
    d_offset(offset)
{}
