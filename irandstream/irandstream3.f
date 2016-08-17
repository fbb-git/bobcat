inline IRandStream::IRandStream(int min, int max, long seed)
:
    Randbuffer(min, max, seed),
    std::istream(this)
{}
