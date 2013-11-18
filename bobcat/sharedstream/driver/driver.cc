#include <iostream>
#include <string>
#include <ostream>
#include <istream>

#include <bobcat/exception>
#include <bobcat/sharedstream>

using namespace std;
using namespace FBB;

int main()
{
    SharedStream shared;

    int id = -1;

    while (true)
    {
        cout << 
                "\n"
                " K             kill (no lock) existing shared segment\n"
                " R             remove existing shared segment\n"
                " S             show stats of current shared segment\n"
                " L <id>        Load segment <id>\n"
                " c            create new shared memory (sets id)\n"
                " l            lock segment id until key pressed\n"
                " p <x> c      put char c at offset x\n"
                " q            quit\n"
                " r <x> <n>    read n chars from offset x\n"
                " w <x> args   write all args at offset x\n"
                "? ";

        char ch;
        cin >> ch;

        ios::off_type offset;

        cout << "Requested: " << ch << '\n';

        shared.clear();

        switch (ch)
        {
            case 'c':
            {
                shared.open(1, SharedStream::kB);

                id = shared.id();
                cout << "id = " << id << '\n';
                shared.memInfo(cout);
                cout << '\n';
            }
            break;
        
            case 'K':         // delete segment
            case 'R':         // delete segment
            {
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }

                cout << "Removing segment id = " << id << '\n';
                if (ch == 'R')
                    shared.remove();
                else
                    shared.kill();

                id = -1;
            }
            break;

            case 'L':
                cin >> id;
                cout << "Loading segment " << id << '\n';
                shared.open(id);
                shared.memInfo(cout);
                cout << '\n';
            break;

            case 'S':
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }
                shared.memInfo(cout);
                cout << '\n';
            break;
            
            case 'p':           // put a char behind the last written
            {
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }

                cin >> offset >> ch;
                if (!cin)
                    throw Exception() << "cmd specification error";
    
                shared.seekp(offset);
                cout << "Segment id = " << id << " at write offset " << 
                                                    shared.tellp() << '\n';
                shared.put(ch);
            }
            break;
                
            case 'r':           // put a char behind the last written
            {
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }

                int n;

                cin >> offset >> n;
                if (!cin)
                    throw Exception() << "cmd specification error";

                char buf[n];

                shared.seekg(offset);
                cout << "Segment id = " << id << " at offset " << 
                         shared.tellg() << ", to read " << n << " bytes\n";
    
                n = shared.read(buf, n).gcount();
    
                if (n < 0)
                    cout << "No data at " << offset << '\n';
                else
                {
                    cout << "Retrieved " << n << " bytes, containing `";
                    cout.write(buf, n);
                    cout << "'\n";
    
                    for (auto ch: buf)
                        cout << static_cast<int>(ch) << ' ';
                    cout << '\n';
                }
            }
            break;
                
            case 'w':           // write chars at offset
            {
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }

                string line;

                cin >> offset;
                getline(cin, line);
                if (!cin)
                    throw Exception() << "cmd specification error";
    
                streampos pos = shared.seekp(offset).tellp();

                cout << "Segment id = " << id << " at offset " << 
                         pos << ", to write " << line.length() << " bytes\n";
    
                
                shared.write(line.data(), line.length());

                if (!shared)
                    cout << "No room left to write any bytes\n";
                else
                    cout << "Wrote " << (shared.tellp() - pos) << " bytes\n";
            }
            break;
                
            case 'q':
            return 0;

            default:
                cout << "request not implemented: " << ch << '\n';
            break;
        }
    }
}

