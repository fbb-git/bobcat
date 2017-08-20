/*
                              driver.cc
*/


#include <iostream>

#include <bobcat/csv4180>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
//    if (argc == 1)
//        cout << "arg1: file containing csv lines\n";

//    CSV4180 csv{ "SXS" };    
//    CSV4180 csv{ "SXS", true };    
    CSV4180 csv;    
//    CSV4180 csv{3};    
//    CSV4180 csv{3, true};    

//    cout << "? ";
//    if (not csv.read1(cin))
//    {
//        cerr << "Error in input line\n";
//        return 0;
//    }

    size_t nLines = csv.read(cin);
    cerr << nLines << " lines were read\n";
    if (not csv.header().empty())
    {
        cerr << "header: " << '\n';
        for (auto const &field: csv.header())
            cerr << "   `" << field << "'\n";
    }

    cerr << "# CSV values: " << csv.nValues() << '\n';
    for (auto const &line: csv.data())
    {
        cerr << "Line:\n";
        for (auto const &entry: line)
            cerr << "   `" << entry << "'\n";
    }
}





