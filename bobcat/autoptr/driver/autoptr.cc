#include "../autoptr"

using namespace std;
using namespace FBB;

int main()
{
    AutoPtr<int> autoInt(new int(4));
    cout << "\n1: test simple construction and copy construction\n\n";

        {
            AutoPtr<int> auto2(autoInt);
            cout << *auto2 << endl;    
            cout << *(auto2 + 0) << endl;    
        }
        cout << *autoInt << endl;    
    
    cout << "\n2: test array\n\n";

        {
            AutoPtr<int> autoarr(new int[5], 5);
        
            autoarr[1] = 1;
            autoarr[2] = 2;
        
            cout << autoarr[2] << endl;
            cout << autoarr[3] << endl;
    
    cout << "\n3: assign to former autoPtr of different data size\n\n";

            autoInt = autoarr;
        }
        
        cout << autoInt[2] << endl;
        cout << autoInt[3] << endl;

    cout << "\n4: pointer-based operations\n\n";
  
        cout << *((autoInt + 4) - 2) << endl;
      
        cout << *((autoInt + 6) - 4) << endl;
        cout << ((autoInt + 6) - 4)[0] << endl;
    
    cout << "\n5: resetting\n\n";

        AutoPtr<int> autoSave(autoInt);
    
        autoInt.reset(new int(12345));
        cout << *autoInt << endl;
        cout << autoSave[2] << endl;

    cout << "\n6: resetting all\n\n";

        autoSave = autoInt;
    
        autoInt.resetAll(new int(12345));
        cout << *autoInt << endl;
        cout << *autoSave << endl;

}

