inline bool SharedPos::eof() const
{
    return d_offset >= d_sharedData->nReadable();
}
