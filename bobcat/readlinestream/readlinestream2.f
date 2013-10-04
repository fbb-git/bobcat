inline ReadLineStream::ReadLineStream(std::string const &prompt, 
                                      size_t historySize, Type type)
:
    std::istream(&ReadLineBuf::initialize(prompt, historySize, type)),
    d_readLineBuf(ReadLineBuf::instance())
{}
