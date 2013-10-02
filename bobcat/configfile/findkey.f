inline string ConfigFile__::findKey(string const &keyPattern, size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(\\S+)", count);
}
