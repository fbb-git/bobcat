inline void SharedStreambuf::setOpenMode(std::ios::openmode openMode)
{
    d_openMode = openMode;
    d_currentMode = openMode;
}
