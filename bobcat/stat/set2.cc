#include "stat.ih"

bool Stat::set(string const &name, string const &pathlist)
{
    if (name[0] == '/')
        return set(name);

    vector<string> element;
    String::split(&element, pathlist, ":");

    for 
    (
        vector<string>::iterator it = element.begin(); 
            it != element.end(); 
                ++it
    )
    {
        if (set(*it + "/" + name))
            return true;
    }

    return false;
}









