#include "cmdfinderbase.ih"

void CmdFinderBase::useFirstCmd(std::string const &cmd)
{
    istringstream in(cmd);

    in >> d_cmd >> d_beyond;

    string trailer;
    getline(in, trailer);
    d_beyond += trailer;
}
