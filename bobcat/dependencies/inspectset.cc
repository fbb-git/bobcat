#include "main.ih"

bool inspectSet(StringSet &requiredSet, Map &table)
{
    bool modified = false;

    for (auto &required: requiredSet)           // visit all required classes
    {
        StringSet updated{requiredSet};       // possibly extended set

                                                // the required set if a 
                                                // required class:
        StringSet const &reqByRequired = table[required];

                                                // add elements to `updated'
        updated.insert(reqByRequired.begin(), reqByRequired.end());

        if (requiredSet.size() < updated.size())
        {
            modified = true;
            requiredSet = updated;
        }
    }
    return modified;
}
