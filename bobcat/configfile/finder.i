inline bool ConfigFile__::finder(string const &haystack, string const &needle)
{
    return haystack.find(needle) != string::npos;
}
