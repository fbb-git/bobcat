inline void Pattern::newRegex(string const &pattern, int options)
{
    d_regex = new Regex(pattern, options);
}
