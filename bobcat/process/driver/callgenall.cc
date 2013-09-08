
#include <unistd.h>
#include <iostream>
#include <thread>

#include <bobcat/process>
#include <bobcat/stringline>

using namespace FBB;
using namespace std;

Process genall("./genall");


void genout()
{
    string line;
    while (getline(genall, line))
        cout << line << '\n';
}

int main()
{
    genall.start();

//    thread outThread(genout);

    string line;

    while (getline(cin, line))
        genall << line << endl;
    genall.close();

    while (getline(genall , line))
        cout << "cout: " << line << endl;

    while (getline(genall.cerr() , line))
        cout << "cerr: " << line << endl;

    genall.stop();
    genall.waitForChild();
}
