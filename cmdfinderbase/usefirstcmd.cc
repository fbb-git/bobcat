#include "cmdfinderbase.hh"

void CmdFinderBase::useFirstCmd(std::string const &cmd)
{
    istringstream in(cmd);

    d_beyond.erase();         // clear any old remaining `beyond' info

    in >> d_cmd >> d_beyond;

    string trailer;
    getline(in, trailer);
    d_beyond += trailer;
}
