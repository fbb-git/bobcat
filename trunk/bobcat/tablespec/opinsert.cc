#include "tablespec.ih"

std::ostream &operator<<(std::ostream &str, FBB::TableSpec const &tableType)
{
    return tableType.insert(str);
}
        
