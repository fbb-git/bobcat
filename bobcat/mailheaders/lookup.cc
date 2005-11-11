#include "mailheaders.ih"

namespace
{
    class MatchObj
    {
        char const * d_hdr;
        unsigned d_idx;
        void (MatchObj::*matchfun)(MailHeaders::HdrPair const &hdrIndex);

        public:
            MatchObj(char const *hdr, MailHeaders::Match type)
            :
                d_hdr(hdr),
                d_idx(0),
                matchfun
                (
                    type == MailHeaders::FULL    ? &MatchObj::full    :
                    type == MailHeaders::INITIAL ? &MatchObj::initial :
                                                   &MatchObj::partial
                )
            {}

            void operator()(MailHeaders::HdrPair const &hdrIndex)
            {
                (this->*matchfun)(hdrIndex);
                d_idx++;
            }

        private:
            void full(MailHeaders::HdrPair const &hdrIndex)
            {
                if (hdrIndex.first == d_hdr)
                    throw d_idx;
            }
            
            void partial(MailHeaders::HdrPair const &hdrIndex)
            {
                if (hdrIndex.first.find(d_hdr) != string::npos)
                    throw d_idx;
            }
            
            void initial(MailHeaders::HdrPair const &hdrIndex)
            {
                if (hdrIndex.first.find(d_hdr) == 0)
                    throw d_idx;
            }
    };
}
                
string::size_type MailHeaders::lookup(char const *header, Match type) const
{
        // look for the first header matching `header', using
        // match-strategy `type' If found, the MatchObj throws the
        // index as an exception, which is then returned. Otherwise,
        // npos is returned.
    try
    {
        for_each(d_index.begin(), d_index.end(), MatchObj(header, type));
        return string::npos;
    }
    catch (string::size_type idx)
    {
        return idx;
    }
    return string::npos;
}
