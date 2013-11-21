inline std::ostream &operator<<(std::ostream &out, SharedMemory const &mem)
{
    return mem.insert(out);
}
