inline size_t String::split(
                        SplitPairVector *entries, std::string const &str,
                        char const *sep, bool addEmpty)
{
    return split(entries, str, addEmpty ? TOKSEP : TOK, sep);    
}



