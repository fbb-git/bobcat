#include "tablespec.ih"

namespace FBB
{

std::ostream &operator<<(std::ostream &str, TableSpec const &tableType)
{
    return tableType.insert(str);
}
        
}
