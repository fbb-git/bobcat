
#include <fstream>
#include <iostream>
#include <bobcat/diffiehellman>

using namespace FBB;
using namespace std;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        DiffieHellman dh(1024, 5, true);
        dh.save("init", DiffieHellman::SAVE_SECRET_KEY);
    }

    if (argc == 2)
    {
        DiffieHellman dh("init.pub");
        dh.save("peer", DiffieHellman::SAVE_SECRET_KEY);

        string key = dh.key();
        cout << "Key length: " << key.length() << '\n';
        ofstream outkey("peerkey");
        outkey.write(key.data(), key.length());
    }

    if (argc == 3)
    {
        DiffieHellman dh("init.pub", "init.sec");

        string key = dh.key("peer.pub");
        cout << "Key length: " << key.length() << '\n';
        ofstream outkey("initkey");
        outkey.write(key.data(), key.length());
    }

}
catch (std::exception const &exc)
{
    std::cout << exc.what() << '\n';
}

