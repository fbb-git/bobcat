template <typename Rep, typename Period>
inline std::cv_status SharedCondition::wait_for(
            std::chrono::duration<Rep, Period> const &relTime)
{
    return wait_until(std::chrono::system_clock::now() + relTime);
}
