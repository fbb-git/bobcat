template <typename Type>
Type *SharedSegment::detach(Type *sharedPtr, bool requireOK)
{
    rawDetach(sharedPtr, requireOK);
    return 0;
}
