#include "main.ih"

void fill(Map &table)
{
    string line;
    string key;
    string value;

    while (getline(cin, line))
    {
        istringstream in(line);

        if (not isblank(line[0]))   // add ^key to the table
        {
            in >> key;
            table.insert(ValueType{ key, ValuePair{StringSet{}, false} });
        }
        else                        // add \s+value to the table, and 
        {                           // indicate that it depends on 'key'
            in >> value;            
            table[value].first.insert(key);
        }
    }
}
