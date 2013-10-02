inline IRandStream::IRandStream(int min, int max)
:
    Randbuffer(min, max, 1),
    std::istream(this)
{}
