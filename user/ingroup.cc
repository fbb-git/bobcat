#include "user.ih"

bool User::inGroup(size_t gid, bool useEffective) const
{
    size_t size = getgroups(0, 0);
    size_t listSize = size + useEffective;

    gid_t *list = new gid_t[listSize];

    size_t nGroups = getgroups(size, list);
    if (useEffective)
        list[size] = getegid();

    bool ret = find(list, list + nGroups, gid) != list + nGroups;

    delete[] list;

    return ret;
}
