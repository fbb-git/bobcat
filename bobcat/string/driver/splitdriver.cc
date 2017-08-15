// compile with 
//  gx splitdriver.cc -L ../tmp/ -lstring -lbobcat

#include <iostream>
#include "../string"

using namespace std;
using namespace FBB;

char const *typeName[] = 
{
    "DQUOTE_UNTERMINATED",    // unterminated d-quoted element
    "SQUOTE_UNTERMINATED",    // unterminated s-quoted element
    "ESCAPED_END",            // word with plain \ at the end
    "SEPARATOR", // separator encountered
    "NORMAL", // normal string-element in the original string
    "DQUOTE", // string-element originally surrounded by " chars
    "SQUOTE", // string-element originally surrounded by ' chars
};

//    enum SplitType
//    {
//        TOK,            // 0 acts like strtok (10: addEmpty == false)
//        TOKSEP,         // 1 same, returns separators (11: addempty true)
//        STR,            // 2 acts like strstr
//        STRSEP,         // 3 same, but return separators
//    };

int main(int argc, char **argv)
{
    while (true)
    {
        cout << "? ";
    
        int type;
        cin >> type;
        cin.ignore();

        string line;
        if (not getline(cin, line))
            break;

//        vector<String::SplitPair> vect{
//                type >= 10 ?
//                    String::split(line, ",", type == 11) 
//                :
//                    String::split(line, 
//                            static_cast<String::SplitType>(type), ",") };

//        vector<String::SplitPair> vect;
//        if (type >= 10)
//            String::split(&vect, line, ",", type == 11);
//        else
//            String::split(&vect, line, 
//                          static_cast<String::SplitType>(type), ",");

//        for (auto const &element: vect)
//            cout << '`' << element.first << "': " << 
//                                typeName[element.second] << '\n';

//        String::Type strType;
//        vector<string> vect{ 
//                type >= 10 ?
//                    String::split(&strType, line, ",", type == 11)
//                :
//                    String::split(&strType, line, 
//                            static_cast<String::SplitType>(type), ",")
//                };
//
//        cout << "Final type: " << strType << '\n';

        vector<string> vect;
                if (type >= 10)
                    String::split(&vect, line, ",", type == 11);
                else
                    String::split(&vect, line, 
                            static_cast<String::SplitType>(type), ",");

        for (auto const &element: vect)
            cout << '`' << element << "'\n";
   }
}




