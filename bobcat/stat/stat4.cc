#include "stat.ih"

#include "../iuo/iuo"

Stat::Stat(Stat const &&tmp)
:
    d_stat(tmp.d_stat),
    d_errno(tmp.d_errno),

    d_name( move(tmp.d_name) )
{
    static bool called = false;
    deprecated__(called, "Stat::Stat(Stat const &&tmp) is "
                "deprecated. Please recompile this program");
}
