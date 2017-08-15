inline String::SplitPair::SplitPair(char ch, Type type)
:
    std::pair<std::string, Type>(std::string{ 1, ch }, type)
{}

