#include "hostent.ih"

#include "../iuo/iuo"

Hostent::Hostent(Hostent const &&tmp)
{
    static bool called = false;
    deprecated__(called, "Hostent::operator=(Hostent const &&tmp)");

    swap(const_cast<Hostent &>(tmp));
    const_cast<Hostent &>(tmp).h_name = 0;  // prevent tmp's ~Hostent from
                                            // deleting wild pointers
}

