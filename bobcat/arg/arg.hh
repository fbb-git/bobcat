#include "arg"

#include <iostream>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unistd.h>

#include <bobcat/exception>
#include <bobcat/string>
#include <bobcat/iuo>

namespace FBB
{

class Arg__: public ArgTypes__
{
    friend class Arg;

    typedef FBB::LongOption__ LongOption;
    typedef struct option                           OptStruct;
    typedef std::vector<std::string>                StringVector;
    typedef std::unordered_map<int, StringVector>   IntStringVectorMap;
    typedef IntStringVectorMap::const_iterator      ISVMapIterator;
    typedef std::unordered_map<std::string, StringVector> 
                                                    StringStringVectorMap;
    typedef StringStringVectorMap::const_iterator   SSVMapIterator;

    std::string                     d_base;
    char const                      **d_argPointer;
    
    std::vector<std::string>        d_argv;     // remaining arguments
                                                // after removing the 
                                                // options

    IntStringVectorMap d_optv;                  // short (and associated
                                                // long options). 
                                                // 1st value: option char;
                                                // 2nd value: optionvalue
                                                //      or empty string.
    size_t           d_nOptv;                   // count of ALL of the
                                                // previous options

    StringStringVectorMap   d_longOptv;         // specified long options
    size_t                  d_nLongOptions;     // count of ALL of the
                                                // following options

    char const          *d_msg;                 // info about erroneous opt.
    int                  d_getOpt;              // value returned by getopt()
    int                  d_beyondDashes;        // idx of 1st arg beyond --

    static std::string    s_dirsep;
    static char           s_optChar[];          // used by the constructors
        
    public:
        int beyondDashes() const;               // .i
        std::string const &basename() const;    // .i
        size_t nArgs() const;                   // .i

            // total number of specified short (and combined long) options
        size_t nOptions() const;                // .i

            // total numer of long-only options specified
        size_t nLongOptions() const;            // .i

        size_t option(int option) const;                        // 1
        size_t option(std::string const &optchars) const;       // 2
        size_t option(size_t idx, 
                        std::string *value, int option) const;  // 3
        size_t option(std::string *value, int optChar) const;
        size_t option(size_t *idx, 
                        std::string *value, int option) const;  // 4
        size_t option(size_t idx, std::string *value, 
                        char const *longOption) const;          // 5
        //size_t option(std::string *value, char const *longOption) const;
        size_t option(size_t *idx, std::string *value, 
                char const *longOption) const;                  // 6

        char const *operator[](size_t idx) const;

        void versionHelp(void (*usage)(std::string const &progname), 
            char const *version, size_t minArgs, int helpFlag = 'h', 
            int versionFlag = 'v') const;

        char const **argPointers();
    private:
        Arg__(Arg__ const &other) = delete;
        Arg__ &operator=(Arg const &other) = delete;

        friend class ArgConfig;     // accesses the constructors and
                                    // longOption()
                                                            // 1
        Arg__(char const *optstring, int argc, char **argv);

        Arg__(char const *optstring,                          // 2
            LongOption const * const begin,
            LongOption const * const end,
            int argc, char **argv);

        void addCharOption();       // in d_getOpt
        void addLongOption(std::string const &longName);    // 1
        void addLongOption(OptStruct *optStructs,           // 2
                        std::string const &optString,
                        LongOption const &longOption);

        void verify();          

        size_t firstNonEmpty(size_t *idx, std::string *value, 
                        StringVector const &sv) const;

        void setBasename(std::string const &argv0);
        void fillLongOptions(
                        OptStruct *optStructs,
                        std::string const &optString,
                        LongOption const * const begin,
                        LongOption const * const end);
        bool plainLongOption(LongOption const &longOption);
        int setOptionType(std::string const &optString,
                        LongOption const &longOption);
};

#include "beyonddashes.f"
#include "basename.f"
#include "nargs.f"
#include "nlongoptions.f"
#include "noptions.f"
#include "opindex.f"

} // FBB

using namespace FBB;
using namespace std;

