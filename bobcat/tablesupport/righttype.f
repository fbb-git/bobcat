inline void TableSupport::rightType(size_t *target, size_t type)
{
    *target =   *target != SKIP || (type & (USE | RIGHT_FULL)) ? 
                    USE 
                : 
                    RIGHT_MID;
}
