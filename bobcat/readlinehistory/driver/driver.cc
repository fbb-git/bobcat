#include <iostream>
#include <algorithm>

#include <bobcat/datetime>
#include <bobcat/readlinestream>
#include <bobcat/readlinehistory>

using namespace std;
using namespace FBB;

void showHis(ReadLineHistory::HistoryElement const &element)
{
    cout << element.timestamp() << ": " << element.line() << '\n';
}

string timestamp()
{
    return DateTime().rfc2822();
};

int main()
{
    ReadLineStream in("? ", ReadLineBuf::EXPAND_HISTORY);
    in.useTimestamps(&timestamp);

    cout << "Enter some lines, end the input using ctrl-d\n";
    string line;
    while (getline(in, line))
        ;

    ReadLineHistory &history = ReadLineHistory::instance();

    cout << "All lines, from the first to the last:\n";
    for_each(history.begin(), history.end(), showHis);

    cout << "\n"
            "All lines, from the last to the first:\n";
    for_each(history.rbegin(), history.rend(), showHis);
}







