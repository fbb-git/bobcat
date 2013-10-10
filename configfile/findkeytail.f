inline string ConfigFile__::findKeyTail(string const &keyPattern, size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(.*)\\s*$", count);
}
