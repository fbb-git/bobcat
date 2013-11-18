inline std::streamsize SharedPos::eos() const
{
    return static_cast<std::streamsize>(blockIdx() + 1) * segmentSize();
}
