inline size_t String::split(std::vector<std::string> *words, 
                            std::string const &str, char const *sep, 
                            bool addEmpty)
{
    return split(words, str, addEmpty ? TOKSEP : TOK, sep);
}

