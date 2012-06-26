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

    size_t mod = mode();

    return
        (       // Read test:
            (mod & OR) ||
            ((mod & UR) && userIsOwner) ||
            ((mod & GR) && userInGroup) ||
            not (spec & READ)
        )
        and
        (       // Write test:
            (mod & OW) ||
            ((mod & UW) && userIsOwner) ||
            ((mod & GW) && userInGroup) ||
            not (spec & WRITE)
        )
        and
        (       // Exec test:
            (mod & OX) ||
            ((mod & UX) && userIsOwner) ||
            ((mod & GX) && userInGroup) ||
            not (spec & EXEC)
        );
}
