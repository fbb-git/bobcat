#include "main.ih"

void inspect(Map &table)
{
    bool modified;

    do
    {
        modified = false;
        for (auto &value: table)  // visit all elements
            modified |= inspectSet(value.second, table);
    }
    while (modified);
}
