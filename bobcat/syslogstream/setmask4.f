inline int SyslogStream::setMask(int maskValue, PriorityType upTo)
{
        // if upTo, maskValue is 2**x, and all its lower bits are also raised
    return setlogmask(upTo == SINGLE ?  
                        maskValue : maskValue |= (maskValue - 1));
}
