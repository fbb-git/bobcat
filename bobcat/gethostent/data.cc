#include "gethostent.ih"

// struct addrinfo 
// {
//     int              ai_flags;
//     int              ai_family;
//     int              ai_socktype;
//     int              ai_protocol;
//     socklen_t        ai_addrlen;
//     struct sockaddr *ai_addr;
//     char            *ai_canonname;
//     struct addrinfo *ai_next;
// };
//
// struct sockaddr {
//     unsigned short    sa_family;    // address family, AF_xxx
//     char              sa_data[14];  // 14 bytes of protocol address
// };
//
// 
// struct in_addr {
//     unsigned long s_addr;          // load with inet_pton()
// };
//
// struct sockaddr_in {
//     short            sin_family;   // e.g. AF_INET, AF_INET6
//     unsigned short   sin_port;     // e.g. htons(3490)
//     struct in_addr   sin_addr;
//     char             sin_zero[8];  // zero this if you want to
// };
//
// struct hostent
// {
//     char    *h_name;        // official name of host
//     char    **h_aliases;    // alias list
//     int     h_addrtype;     // host address type (always AF_INET)
//     int     h_length;       // length of address
//     char    **h_addr_list;  // list of addresses
// }

namespace
{
    char *nullPtr = 0;
};

string              GetHostent::s_name;

in_addr             GetHostent::s_address;
char               *GetHostent::s_addressPtr[2] = 
                    {
                        reinterpret_cast<char *>(&s_address),
                        0
                    };
struct hostent      GetHostent::s_hp
                    {
                        0,              // set to &s_name.front()
                        &::nullPtr, 
                        AF_INET, 
                        4,              // Size of binary IP4 addresses
                        s_addressPtr
                    };    
