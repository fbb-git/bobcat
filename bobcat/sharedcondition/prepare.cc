#include "sharedcondition.ih"

SharedCondition::Data SharedCondition::prepare()
{
    if (d_shmem == 0)
        throw Exception() << "SharedCondition object not initialized";

    Data data {d_shmem->offset()};
    d_shmem->seek(d_offset);
    data.condition = reinterpret_cast<Condition *>(d_shmem->ptr());

    return data;
}
