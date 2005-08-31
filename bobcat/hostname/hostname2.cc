#include "hostname.ih"

/*
    initialize the Hostent part by
        - obtaining a hostent struct from the GetHostent::gethostent()
            function,
        - providing it with the dotted-decimal address obtained from the
            GetHostent::addressToString() function, 
        - which function is given the binary address obtained from the
            InetAddress parameter.
*/

namespace
{
    static char const name[] = "Hostname::Hostname(InetAddress)";
}

Hostname::Hostname(InetAddress const &address) throw(Errno)
:
    Hostent
    (
        GetHostent::gethostent
        (
            ::name, 
            GetHostent::addressToString
            (
                ::name, 
                address.sockaddrPtr()
            )
        )
    )
{
    init();
}

