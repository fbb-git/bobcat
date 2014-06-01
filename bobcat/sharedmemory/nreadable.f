inline std::streamsize SharedMemory::nReadable() const
{
    return d_sharedSegment ? d_sharedSegment->nReadable() : 0;
}
