template <typename StreamType>
void Exception::open(int errnoValue, StreamType &stream, 
                     std::string const &name)
{
    if (stream.is_open())
        stream.close();

    stream.open(name);
    if (!stream)
        throw Exception(errnoValue) << "Can't open `" << name << '\'';
}
