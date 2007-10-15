#include "stat.ih"

char const *Stat::s_specialMode[] = 
{
    "SUID",
    "SGID",
    "Sticky Bit"
};


char const *Stat::s_mode[] = 
{
    "User: Read"
    "User: Write"
    "User: Execute"

    "Group: Read"
    "Group: Write"
    "Group: Execute"

    "Other: Read"
    "Other: Write"
    "Other: Execute"
};

char const *Stat::s_type[] = 
{
    "BLOCK DEVICE",
    "CHARACTER DEVICE",
    "DIRECTORY",
    "FIFO",
    "REGULAR FILE",
    "SOCKET",
    "SYMBOLIC LINK",
};

