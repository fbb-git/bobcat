inline DateTime operator+(DateTime const &left,   // d_type
                               tm const &right)
{
    return DateTime(left) += right;
}   
