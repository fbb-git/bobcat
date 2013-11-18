inline std::ostream &operator<<(std::ostream &out, 
                                SharedSegment const &sharedData)
{
    return sharedData.insert(out);
}
