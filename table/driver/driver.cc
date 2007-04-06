#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include <bobcat/fnwrap1c>
#include <bobcat/table>

using namespace std;
using namespace FBB;

class Support: public TableSupport
{
    public:
        virtual void hline(size_t row) const;
        virtual void vline(size_t col) const;
        virtual void vline() const;
    private:
        static void outLine(Element const &element, ostream &out);
};

void Support::hline(size_t row) const
{
    if (row == 0 || row == nRows())
        out() << setfill('-') << setw(width()) << "-" << setfill(' ');
    else  
    {
        const_iterator fieldIt = begin(row);

        if (fieldIt == end())
            return;

        for_each(fieldIt, end(), 
                FnWrap1c<Element const &, ostream &>(outLine, out()));
    }
    out() << endl;
}

void Support::outLine(Element const &element, ostream &out)
{
    if (element.width == 0)
        return;

    if (element.type == SKIP)
        out << setw(element.width) << " ";
    else
        out << setfill('-') << setw(element.width) << "-" << setfill(' ');
}

void Support::vline(size_t col) const
{
    if (col < sep().size())
        out() << sep()[col];
}

void Support::vline() const
{
    vline(nColumns());
    out() << "\n";
}


int main(int argc, char **argv)
{
    Support support;

    support << 0 << " | " << " | ";

    support << Support::HLine(1, 1, 3); // row[1] separator for cols 1 and 2

    Table tab(support, 3, Table::ROWWISE, Table::EQUALWIDTH);
//    Table tab(support, 3, Table::ROWWISE);
 
    tab << Align(0, std::left);     // set column non-default alignment
    tab.fill(argv + 1, argv + argc);// fill range of values
    cout << tab << endl;            // complete the table and insert
 
    tab << "hello" << "" << "wo";   // add additional elements.
    if (tab.nRows() > 2)
        tab << Align(2, 2, center); // set the layout of a specific element
 
    cout << tab << endl;

    return 0;
}
