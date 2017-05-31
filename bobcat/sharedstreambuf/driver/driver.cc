#include <istream>
#include <ostream>
#include <iostream>

#include <../sharedstreambuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << 
            "argument i <id> shows info about the shared memory segment id\n"
            "argument W uses write() to write info to a shared stream,\n"
            "           displaying its id\n"
            "argument w writes info to a shared stream, displaying its id\n"
            "argument R <id> use read() to read info from shared stream <id>\n"
            "argument r <id> reads the written info from shared stream <id>\n"
            "argument k <id> kills shared memory segment <id>\n";
        return 0;
    }

    SharedStreambuf buf;

    switch (argv[1][0])
    {
        case 'W':
        {
            buf.setMemory(SharedMemory(1, SharedMemory::SizeUnit::kB));
            ostream out(&buf);
            string text = "hello world\n";
            out.seekp(0);
            out.write(text.data(), text.length());
            cout << "Memory id = " << buf.id() << '\n';
            break;
        }

        case 'w':
        {
            buf.setMemory(SharedMemory(1, SharedMemory::SizeUnit::kB));
            ostream out(&buf);
            out.seekp(0, ios::end);
            out << "hello world\n";
            cout << "Memory id = " << buf.id() << '\n';
            break;
        }

        case 'R':
        {
            buf.setMemory(SharedMemory(stoul(argv[2])));
            istream in(&buf);
            char buffer[100];
            in.seekg(0);            // essential!
            in.read(buffer, 99);
            buffer[in.gcount()] = 0;
            cout << "Raw read returns `" << buffer << "'\n"
                    "now at offset " << in.tellg() << ", having read " <<
                    in.gcount() << " chars.\n";
            break;
        }

        case 'r':
        {
            buf.setMemory(SharedMemory(stoul(argv[2])));
            istream in(&buf);

            in.seekg(0);            // essential!
            string text;
            getline(in, text);
            cout << "read returns `" << text << "'\n"
                    "now at offset " << in.tellg() << "\n";
            break;
        }

        case 'i':
        {
            buf.setMemory(SharedMemory(stoul(argv[2])));
            buf.memInfo(cout);
            break;
        }
            
            
        case 'k':
        {
            SharedMemory(stoul(argv[2])).kill();
            break;
        }
            
    }
}
catch (exception const &exc)
{
    cout << "Exc.: " << exc.what() << '\n';
}
