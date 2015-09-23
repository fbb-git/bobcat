#include "stat.hh"

Stat::Stat(Stat &&tmp)
:
    d_stat(tmp.d_stat),
    d_errno(tmp.d_errno),

    d_name( move(tmp.d_name) )
{}
