#include "arg.ih"

void Arg__::help() const
{
    if (d_usage == 0)
        throw Exception{} << "Arg::help() called, but no usage available";

    (*d_usage)(basename());
}

void Arg::help() const
{
    d_ptr->help();
}
