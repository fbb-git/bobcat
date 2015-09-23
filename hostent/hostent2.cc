#include "hostent.hh"

Hostent::Hostent(Hostent &&tmp)
{
    swap(tmp);
    tmp.h_name = 0;  // prevent tmp's ~Hostent from deleting wild pointers
}

