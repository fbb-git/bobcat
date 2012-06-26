#include "stat.ih"

bool Stat::access(User const &user, size_t spec, bool useEffective) const
{
    bool userIsOwner = 
            (spec & (UR | UW | UX)) 
            && 
            (
                user.userid() == uid() 
                or 
                (useEffective && user.eUserid() == uid())
            );

    bool userInGroup = 
            (spec & (GR | GW | GX))
            &&
            user.inGroup(gid(), useEffective);

    bool readTest = 
            (spec & OR) ||
            ((spec & UR) && userIsOwner) ||
            ((spec & GR) && userInGroup) ||
            not (spec & READ);

    bool writeTest = 
            (spec & OW) ||
            ((spec & UW) && userIsOwner) ||
            ((spec & GW) && userInGroup) ||
            not (spec & WRITE);

    bool execTest = 
            (spec & OX) ||
            ((spec & UX) && userIsOwner) ||
            ((spec & GX) && userInGroup) ||
            not (spec & EXEC);

    return readTest && writeTest && execTest;
}


