SharedCondition &SharedStreambuf::createSharedCondition(
                                                    std::streamsize *offset)
{
    return SharedCondition::create(offset, d_memory); 
}
