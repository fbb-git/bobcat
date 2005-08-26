#include "equalwidth"

std::ostream &operator<<(std::ostream &str, 
                            FBB::equalWidth const &ew)
{
    return ew.insertInto(str);
}
