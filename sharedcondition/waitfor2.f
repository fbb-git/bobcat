template <typename Rep, typename Period, typename Predicate>
inline bool SharedCondition::wait_for(
            std::chrono::duration<Rep, Period> const &relTime, 
            Predicate pred)
{
    return wait_until(std::chrono::system_clock::now() + relTime, pred);
}
