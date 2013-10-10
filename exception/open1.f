template <typename StreamType>
void Exception::open(StreamType &stream, std::string const &name)
{
    if (stream.is_open())
        stream.close();

    stream.open(name);
    if (!stream)
        throw Exception() << "Can't open `" << name << '\'';
}
