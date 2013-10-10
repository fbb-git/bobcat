inline bool ReadLineStream::useTimestamps(std::string (*timestamp)())
{
    return d_readLineBuf.useTimestamps(timestamp);
}
