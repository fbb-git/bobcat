template <typename StreamType>
void Exception::open(int errnoValue, StreamType &stream, 
                        std::string const &name, std::ios::openmode mode)
{
    if (stream.is_open())
        stream.close();

    stream.open(name, mode);
    if (!stream)
        throw Exception(errnoValue) << "Can't open `" << name << '\'';
}
