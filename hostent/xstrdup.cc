#include "hostent.hh"

char *Hostent::xstrdup(char const *src)
{
    return
        src ?
            strcpy(new char[1 + strlen(src)], src)
        :
            0;
}
