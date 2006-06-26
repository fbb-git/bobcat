/*
                              driver.cc
*/

#include <iostream>
#include <string>
#include <sstream>

#include "../refcount.h"

using namespace std;
using namespace FBB;

// The class Data uses reference counting. Data are shared until they are
// modified. 

class Data: public RefCount
{
    static unsigned s_n;        // count the number of objects in use

    public:
        Data()                  // all other constructors are built like this:
        {                       // using RefCount's default constructor.
            s_n++;
            cout << "Data(), " << s_n << " Data objects created\n";
        }

        virtual ~Data()
        {
            s_n--;
            cout << "~Data(), " << s_n << " Data objects left\n";
        }

        string accessor() const
        {
            ostringstream ostr;
            ostr << "calling Data::accessor(). Data at " << this;
            return ostr.str();
        }

        void modifier()             // a plain modifier
        {
            cout << "calling Data::modifier(). Data at " << this << endl;
        }

                                    // support function for operator>>()
        istream &extract(istream &istr) 
        {
            cout << "extraction from istream. " <<
                                    "Enter a non-empty line of text" << endl;
            string s;
            getline(istr, s);

            cout << "Read: " << s << endl;

            return istr;
        }
                                    // another modifier: operator+=()
        Data &operator+=(Data const &rvalue)
        {
            cout << "calling Data::operator+=(): @`" << 
                    this << "' += @`" << &rvalue << "'\n";
            return *this;
        }

    private:
        Data &operator=(Data const &other);   // NI

        Data(Data const &other) // The copy constructor MUST call RefCount's
        :                       // CC. Data(Data) is a convenience function 
                                // for clone() and should not be available to 
            RefCount(other)     // clients, thus enforcing the use of 
        {                           // clone() / share() / release()
            s_n++;
            cout << "Data(Data const &), " << s_n << " Data objects created\n";
        }

        virtual RefCount *clone() const
        {
            cout << "Data::clone()\n";
            return new Data(*this);
        }
};


// Client: uses a pointer to a Data object. It is implemented in an 
// almost standard way. Deviations are:
//  *. Copy():       should call share() rather than new Data(*d_dataPtr)
//  *. Destroy():    should call release() rather than delete d_dataPtr;
//  *. non-const members modifying d_dataPtr's data"    
//                   should call Data:modifying() first.
class Client 
{
                                                     // modifying friend
                                                     // see below at modifier()
    friend istream &operator>>(istream &istr, Client &c)
    {   
        return Data::modifying(&c.d_dataPtr).extract(istr);
    }

    Data *d_dataPtr;   

    public:
            // Constructors, destructor, overloaded assignment operator: all
            // follow my standard copy() / destroy() approach. 

        Client()                    // new object, creates its own data
        :                           // use new Data(...) to initialize.
            d_dataPtr(new Data())
        {}

        ~Client()
        {
            destroy();
        }

        Client(Client const &other)
        {
            copy(other);
        }

        Client &operator=(Client const &other)
        {
            if (this != &other)
            {
                destroy();
                copy(other);
            }
            return *this;
        }

        string accessor() const         // accessors shadow Data's members
        {                               
            return d_dataPtr->accessor();
        }
                                        // modifiers call modifying first

        void modifier()                 // simple modifier
        {                               
            Data::modifying(&d_dataPtr).modifier();
        }
                                        // arithmetic assignment modifier
        Client &operator+=(Client const &other)
        {                               
            Data::modifying(&d_dataPtr).operator+=(*other.d_dataPtr);
            return *this;
        }

    private:
        void copy(Client const &other)  // copying is sharing: call share()
        {
            d_dataPtr = Data::share(other.d_dataPtr);
        }
        void destroy()                  // destroying is disassociation: call
        {                               // release
            d_dataPtr->release();
        }
};


unsigned Data::s_n = 0;

Client const operator+(Client const &lvalue, Client const &rvalue)
{
    return Client(lvalue) += rvalue;
}

int main()
{
    cout << "Construction:\n";
    Client c;

    cout << "Extraction c from cin:\n";
    cin >> c;

    cout << "c's Modifier called:\n";
    c.modifier();

    cout << "operator += :\n";
    c += c;

    cout << "operator + :\n";
    c + c;

    cout << "Copy construction:\n";
    Client c2(c);

    cout << "Assignment:\n";
    c = c2;

    cout << "Accessors:\n";
    cout << "access c:  " << c.accessor() << endl;
    cout << "access c2: " << c2.accessor() << endl;

    cout << "operator += :\n";
    c += c;

    cout << "c's Modifier called:\n";
    c.modifier();

    cout << "Accessors:\n";
    cout << "access c:  " << c.accessor() << endl;
    cout << "access c2: " << c2.accessor() << endl;

    cout << "c2's Modifier called:\n";
    c2.modifier();

    cout << "resetting refcount to 2:\n";
    c = c2;

    
    cout << "Extraction c from cin:\n";
    cin >> c;

    cout << "End of program:\n";
}
