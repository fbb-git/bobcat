inline Hostent &Hostent::operator=(Hostent &&tmp)
{
    swap(tmp);
    return *this;
}
