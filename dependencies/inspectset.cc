#include "main.ih"

bool inspectSet(ValueType &value, Map &table)
{
    StringSet &requiredSet = value.second.first;
    bool modified = false;

    for (auto &required: requiredSet)           // visit all required classes
    {
        StringSet updated{requiredSet};       // possibly extended set

                                                // the required set of a 
                                                // required class:
        StringSet const &reqByRequired = table[required].first;

                                                // add elements to `updated'
        updated.insert(reqByRequired.begin(), reqByRequired.end());

        if (requiredSet.size() < updated.size())
        {
            string const &key = value.first;
            if 
            (
                not value.second.second
                and reqByRequired.find(key) != reqByRequired.end()
            )
            {
                value.second.second = true;
                cerr << "Circular dependency in class " << key << '\n';
            }
            modified = true;
            requiredSet = updated;
        }
    }
    return modified;
}
