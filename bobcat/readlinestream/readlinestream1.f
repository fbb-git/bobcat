inline ReadLineStream::ReadLineStream(std::string const &prompt, Type type)
:
    std::istream(&ReadLineBuf::initialize(prompt, type)),
    d_readLineBuf(ReadLineBuf::instance())
{}
