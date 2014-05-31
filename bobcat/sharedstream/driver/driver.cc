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
    SharedStream sharedStream;

    int id = -1;

    while (true)
    {
        cout << 
                "\n"
                " K             kill (no lock) existing shared segment\n"
                " S             show stats of current shared segment\n"
                " L <id>        Load segment <id>\n"
                " c            create new shared memory (sets id)\n"
//                " l            lock segment id until key pressed\n"
//                " p <x> c      put char c at offset x\n"
                " q            quit\n"
//                " r <x> <n>    read n chars from offset x\n"
//                " w <x> args   write all args at offset x\n"
                  " i            insert lines (until empty) at the current "
                                                                "offset\n"

                  " x            extract lines (until EOF) from the current "
                                                                "offset\n"
                  " s <x>        seek (abs) offset x\n"
                "? ";

        char ch;
        cin >> ch;

        ios::off_type offset;

        cout << "Requested: " << ch << '\n';

        sharedStream.clear();

        switch (ch)
        {
            case 'c':
            {
                sharedStream.open(1, SharedStream::kB);

                id = sharedStream.id();
                cout << "id = " << id << '\n';
                sharedStream.memInfo(cout);
                cout << '\n';
            }
            break;
        
            case 'K':         // delete segment
            {
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }

                cout << "Removing segment id = " << id << '\n';
                if (ch == 'R')
                    sharedStream.remove();
                else
                    sharedStream.kill();

                id = -1;
            }
            break;

            case 'L':
                cin >> id;
                cout << "Loading segment " << id << '\n';
                sharedStream.open(id);
                sharedStream.memInfo(cout);
                cout << '\n';
            break;

            case 'S':
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }
                sharedStream.memInfo(cout);
                cout << '\n';
            break;
            
            case 's':
            {
                size_t offset;
                if (id == -1)
                {
                    cout << "No segment loaded\n";
                    continue;
                }
                cin >> offset;
                sharedStream.seekg(offset);
                sharedStream.seekp(offset);
                cout << "tellg: " << sharedStream.tellg() << ", "
                        "tellp: " << sharedStream.tellp() << '\n';
            }
            break;
            
            case 'i':
            {
                string line;
                getline(cin, line);
                sharedStream.seekp(0, ios::cur);
                while (true)
                {
                    cout << "? ";
                    if (not getline(cin, line) || line.empty())
                        break;
                    sharedStream << line << endl;
                    cout << 
                            "   tellp: " << sharedStream.tellp() << '\n';
                }
                    cout << // "   tellg: " << sharedStream.tellg() << ", "
                            "   tellp: " << sharedStream.tellp() << '\n';
            }
            break;
                    
            case 'x':
            {
                string line;
                sharedStream.seekg(0, ios::cur);

                while (true)
                {
                    cout << ": ";
                    if (not getline(sharedStream, line))
                        break;
                    cout << line << "\n"
                            "   tellg: " << sharedStream.tellg() << ", "
                            "   tellp: " << sharedStream.tellp() << '\n';
                }
            }
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
    
                sharedStream.seekp(offset);
                cout << "Segment id = " << id << " at write offset " << 
                                                    sharedStream.tellp() << '\n';
                sharedStream.put(ch);
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

                sharedStream.seekg(offset);
                cout << "Segment id = " << id << " at offset " << 
                         sharedStream.tellg() << ", to read " << n << " bytes\n";
    
                n = sharedStream.read(buf, n).gcount();
    
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
    
                streampos pos = sharedStream.seekp(offset).tellp();

                cout << "Segment id = " << id << " at offset " << 
                         pos << ", to write " << line.length() << " bytes\n";
    
                
                sharedStream.write(line.data(), line.length());

                if (!sharedStream)
                    cout << "No room left to write any bytes\n";
                else
                    cout << "Wrote " << (sharedStream.tellp() - pos) << " bytes\n";
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

