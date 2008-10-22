#include <iostream>
#include <string>

#include <memory>
#include <ostream>
#include <istream>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <bobcat/fork>
#include <bobcat/string>
#include <bobcat/pipe>
#include <bobcat/selector>
#include <bobcat/ifdstreambuf>
#include <bobcat/ofdstreambuf>

#include <bobcat/iostream>

using namespace std;
using namespace FBB;

extern std::auto_ptr<Pipe> d_child_inp;          // cin read by the CHILD
extern std::auto_ptr<Pipe> d_child_outp;         // cout written by the CHILD

extern OFdStreambuf    d_childCinbuf;
extern IFdStreambuf    d_childCoutbuf;

extern ostream   d_childCin;            // Parent inserts child cin
extern istream   d_childCout;           // Parent extr. child cout

extern IOStream io;

extern int p1;
extern int p2;
extern int oldIn;
extern int oldOut;

extern pid_t pid;
extern string line;

void close();

Pipe *newPipe();
void newPipes();
void redirectChild();

void childEchoes();
void childLs();
void childSha1();

void parentRedirections();
void parentCat();
void parentOut();
void parentCloseIn();

void finalization();

