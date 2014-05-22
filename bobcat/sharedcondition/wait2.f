template <typename Predicate>
void SharedCondition::wait(Predicate pred)
{
    while (not pred())
        SharedCondition::wait();
}
