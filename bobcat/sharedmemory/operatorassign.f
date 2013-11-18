inline SharedMemory &SharedMemory::operator=(SharedMemory &&tmp)
{
    swap(tmp);
    return *this;
}
