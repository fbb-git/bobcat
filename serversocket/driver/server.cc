#include <iostream>
#include <bobcat/serversocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>

using namespace std;
using namespace FBB;

class IBuf: public FBB::IFilterStreambuf
{
    std::istream *d_in;
    char d_key[sizeof(unsigned long)];
    size_t d_idx = 0;

    size_t const d_maxSize = 100;

    IBuf(unsigned long addr, uint16_t port);

    bool filter(char const **srcBegin, char const **srcEnd) override;

    
};

IBuf::IBuf(std::istream &in, unsigned long addr, uint16_t port)
:
    d_in(in),
    d_key(reinterpret_cast<char const *>(&addr), 
          reinterpret_cast<char const *>(&addr + sizeof(long)), 
{
    char const *cp = reinterpret_cast<char const *>(&port);

    for (auto &ch: d_key)
    {
        ch ^= 
}

bool IBuf::filter(char const **srcBegin, char const **srcEnd)
{
    d_buffer.clear();

    while (d_buffer.size() != d_maxSize)
    {
        char ch;
        if (not d_in.get(ch))
            break;

        ch ^= d_key[d_idx++];
        d_idx %= sizeof(unsigned long);

        d_buffer.push_back(ch);
    }

    if (d_buffer.empty())
        return false;

    *srcBegin = d_buffer.data();
    *srcEnd = d_buffer.data() + d_buffer.size();

    return true;
}

    
    
int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cerr << "Provide server port number\n";
        return 1;
    }

    size_t portnr = stoul(argv[1]);

    ServerSocket server(portnr);

    cerr << "server listens on port " << argv[1] << endl;

    cerr << "serversocket returns:\n" <<
        "address = " << server.dottedDecimalAddress() << endl <<
        "port    = " << server.port() << endl;

    int fd = server.socket();       // open the socket's descriptor

    cout << "File descriptor of the socket is " << fd << endl <<
        "The server terminates when it receives a single `q' on a line\n"
        "A connection is terminated when no input is received anymore.\n"
        "Then another connection is possible" << endl;

    server.listen();                // listen in blocking mode

    while (true)
    {
        SocketBase const fdb = server.accept();
        int fd = fdb.socket();

        unsigned long addr = fdb.sockaddr_inPtr()->sin_addr.s_addr;

        cerr << "Client FD = " << fd << ", " << endl <<
                "address = " << fdb.dottedDecimalAddress() << ", (" <<
                addr << ")\n"
                "communication through port " << fdb.port() << endl;

        IFdStream in(fd);           // stream to read from client
        OFdStream out(fd);          // stream to write to client
        string cmd;
        
        out << (unsigned long)(fdb.port() ^ addr) << endl;

        while (getline(in, cmd))
        {
            cout << "Got: " << cmd << endl;
            out << "Got: " << cmd << "\r" << endl;

            if (cmd[0] == 'q')
                return 0;
        }
        cout << "Ready for another connection\n";
    }
}
catch (exception const &err)
{
    cerr <<
        err.what() << endl <<
        "Server socket on port " << argv[1] << 
        " can't be opened" << endl;
    return -1;
}        

