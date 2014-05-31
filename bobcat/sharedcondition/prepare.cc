#include "sharedcondition.ih"

SharedCondition::Data SharedCondition::prepare()
{
    Data data {d_shmem.offset()};
    d_shmem.seek(d_offset);
    data.condition = reinterpret_cast<Condition *>(d_shmem.ptr());

    return data;
}
