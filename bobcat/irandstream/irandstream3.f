inline IRandStream::IRandStream(int min, int max, int seed)
:
    Randbuffer(min, max, seed),
    std::istream(this)
{}
