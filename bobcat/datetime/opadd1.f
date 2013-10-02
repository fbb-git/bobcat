inline DateTime operator+(DateTime const &left,   // d_type
                               time_t right)
{
    return DateTime(left) += right;
}   
