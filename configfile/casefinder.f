inline bool ConfigFile__::casefinder(string const &haystack,
                                    string const &needle)
{
    return strcasestr(haystack.c_str(), needle.c_str()) != 0;
}
