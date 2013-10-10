inline ReadLineHistory &ReadLineHistory::instance(bool useTimestamps)
{
    return s_readLineHistory.setTimestampsIO(useTimestamps);
}
