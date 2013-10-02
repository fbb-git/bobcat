#include "configfile"

#include <algorithm>
#include <fstream>
#include <cstring>

#include <bobcat/pattern>
#include <bobcat/exception>
#include <bobcat/iuo>

using namespace std;
using namespace FBB;

//    Lines are stored with initial WS removed.
//    If a line ends in \, then the next line (initial WS removed)
//    is appended to the current line.
//    Information at and beyond the first # on individual lines is removed
//    if the rmComment flag is set to true (\# is converted to a #-character)
//    Then, lines containing only blanks and tabs are not stored

namespace FBB
{

class ConfigFile__: public CFEnums__
{
    std::vector<std::string> d_line;

    bool d_rmComment;
    bool d_caseSensitive;
    bool d_indices;
    size_t d_rawIndex;        
    size_t d_nextIndex;        
    std::vector<size_t> d_index;

                            // contains iterators to lines matching REs
    typedef std::vector<std::string>::const_iterator VsIterator;
    typedef std::vector<VsIterator> VsIterVector;
    VsIterVector d_vsIter;
    std::string d_re;

    mutable Pattern d_pattern;

    public:
        explicit ConfigFile__(Comment cType = KeepComment, 
                   SearchCasing sType = SearchCaseSensitive,
                   Indices iType = IgnoreIndices);

                                                // Name of the config file
        explicit ConfigFile__(std::string const &fname,
                    Comment cType = KeepComment, 
                    SearchCasing sType = SearchCaseSensitive,
                    Indices iType = IgnoreIndices);

        ConfigFile__(ConfigFile__ const &rhs) = default;
        ConfigFile__(ConfigFile__ &&tmp) = default;

        ConfigFile__ &operator=(ConfigFile__ &&tmp) = default;
        ConfigFile__ &operator=(ConfigFile__ const &rhs) = default;

        void setCommentHandling(Comment type);                          // .i
        void setSearchCasing(SearchCasing type);                        // .i
        void open(std::string const &fname);

        const_iterator begin() const;                                   // .i
        const_iterator end() const;                                     // .i

        const_RE_iterator beginRE(std::string const &re);
        const_RE_iterator endRE() const;                                // .i

        std::pair<const_RE_iterator, const_RE_iterator> 
                            beginEndRE(std::string const &re);

        const_iterator find(std::string const &target) const;
        const_iterator findRE(std::string const &re) const;

        std::string findKey(std::string const &key, size_t count);      // .i
        std::string findKeyTail(std::string const &key, size_t count);  // .i

        size_t index(size_t lineNr);                            // 1.i
        size_t index(const_iterator const &iterator);           // 2.i

        std::string const &operator[](size_t idx) const;        // opindex.i

        size_t size() const;                                    // .i

    private:
        static void trimLeft(std::string &line);
        static void trimRight(std::string &line, bool appendNext);
        bool rmCommentAndEscapes(std::string &line);
        bool nextLine(std::istream &inStream, std::string &dest);

        void resetVsIter(std::string const &re);
        std::string searchFor(std::string const &keyPattern, size_t count);

        static bool finder(std::string const &haystack,             // .i
                           std::string const &needle);
        static bool casefinder(std::string const &haystack,         // .i
                               std::string const &needle);
};

} // FBB

#include "begin.f"
#include "casefinder.f"
#include "end.f"   
#include "endre.f"
#include "finder.f"
#include "findkey.f"
#include "findkeytail.f"
#include "index1.f"
#include "index2.f"
#include "opindex.f"
#include "setcommenthandling.f"
#include "setsearchcasing.f"   
#include "size.f"




