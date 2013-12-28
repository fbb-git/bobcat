#ifndef INCLUDED_SPAWN_
#define INCLUDED_SPAWN_

#include <string>

#include <fstream>
#include <iostream>

#include <bobcat/fork>

#include <bobcat/pipe>
#include <bobcat/ifdstreambuf>
#include <bobcat/ofdstreambuf>
#include <bobcat/ifdstream>

class Spawn: public FBB::Fork, public std::ostream// , public std::istream
{
    FBB::Pipe d_insertPipe;
//    FBB::Pipe d_extractPipe;
//    FBB::Pipe d_errPipe;

    FBB::OFdStreambuf d_insertBuffer;
//    FBB::IFdStreambuf d_extractBuffer;
//    FBB::IFdStream d_errStream;

    std::string d_command;

    public:
        Spawn(std::string const &command);
    
        void end();

    private:
        void childProcess() override;
        void parentProcess() override;
        void childRedirections() override;
};
        
#endif





