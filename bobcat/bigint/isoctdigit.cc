#include "bigint.hh"

namespace FBB
{

int isoctdigit(int ch)
{
    return strchr("01234567", ch) != 0;
}

}
