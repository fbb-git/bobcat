inline Process &Process::operator+=(std::string const &command)
{
    d_command += command;
    return *this;
}
