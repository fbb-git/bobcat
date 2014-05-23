inline size_t SharedMemory::dataSegmentSize() const
{
    return d_sharedSegment ? d_sharedSegment->segmentSize() : 0;
}
