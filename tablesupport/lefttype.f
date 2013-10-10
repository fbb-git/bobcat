inline void TableSupport::leftType(size_t *target, size_t type)
{
    *target =   *target != SKIP || (type & (USE | LEFT_FULL)) ? 
                    USE 
                : 
                    LEFT_MID;
}
