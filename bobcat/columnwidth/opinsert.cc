#include "columnwidth"

std::ostream &operator<<(std::ostream &str, 
                            FBB::columnWidth const &cw)
{
    return cw.insertInto(str);
}
