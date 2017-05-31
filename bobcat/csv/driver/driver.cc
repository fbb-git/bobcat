#include <iostream>
#include <../csv>

using namespace std;
using namespace FBB;

int main()
{
    CSV csv("I5 X2 S2 D3");

    cin >> csv;

    cout << 
        "Nr. of field specs: " << csv.length() << "\n"
        "Nr. of fields: " << csv.size() << "\n"
        "Nr. of available fields: " << csv.count() << "\n"
        "Field 2 as int via get: " << csv.get<int>(2) << "\n"
        "Field 2 as int via available: " << csv.field<int>(2) << "\n"
        "Field 3 via operator[]: " << csv[3] << "\n"
        "Field 6 as string via get: " << csv.get<string>(6) << "\n"
        "Field 6 as string via available: " << csv.field<string>(6) << "\n"
    ;

    cout << "First element as string: " << *csv.begin() << "\n";

    cout << "All elements as strings:\n";
    copy(csv.begin(), csv.end(), ostream_iterator<string>(cout, " "));
    cout << '\n';
    
    cout << "All elements as ints:\n";
    copy(csv.begin<int>(), csv.end<int>(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    cout << "All elements as strings, backward:\n";
    copy(csv.rbegin(), csv.rend(), ostream_iterator<string>(cout, " "));
    cout << '\n';
    
    cout << "All elements as ints, backward:\n";
    copy(csv.rbegin<int>(), csv.rend<int>(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    cout << "Insert LENGTH (default):\n" <<
            csv << '\n';

    csv.setInsertType(CSV::SIZE);

    cout << "Insert SIZE:\n" <<
            csv << '\n';

    csv.setInsertType(CSV::COUNT);

    cout << "Insert COUNT:\n" <<
            csv << '\n';
}


