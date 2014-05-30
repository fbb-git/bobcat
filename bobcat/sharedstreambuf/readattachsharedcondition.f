inline SharedCondition &SharedStreambuf::readAttachSharedCondition(
                                    std::ios::off_type offset, 
                                    std::ios::seekdir way)
{
    return SharedCondition::readAttach(d_memory, offset, way); 
}
