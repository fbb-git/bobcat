template <typename FP>
FP CmdFinder<FP>::findCmd(std::string const &cmd)
{
    (this->*d_useCmd)(cmd);     // store the cmd to use

    FunctionPtr fp;
    MatchKey matchKey(&fp, this);   // create an object matching 
                                    // a cmd with a key

                                // count the number of occurrences
    d_count = std::count_if(d_begin, d_end, matchKey);

                         
    return d_count == 1 ?   
                fp              // return fp if cmd found
            :                   // otherwise return the last fptr
                (d_end - 1)->second;
}
