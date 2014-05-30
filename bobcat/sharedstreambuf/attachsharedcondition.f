SharedCondition &SharedStreambuf::attachSharedCondition(
                                        std::ios::off_type offset,
                                        std::ios::seekdir way)
{
    return SharedCondition::attach(d_memory, offset, way); 
}
