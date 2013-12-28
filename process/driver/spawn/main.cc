#include "spawn.h"

using namespace std;

int main(int argc, char **argv)
try
{
    Spawn spawn(argv[1]);

    ifstream in(argv[2]);
    
    spawn.fork();

    spawn << in.rdbuf();

    spawn.end();

}
catch (int x)
{
    return 0;
}
