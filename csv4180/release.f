inline CSV4180::DataVector CSV4180::release()
{
    return std::move(d_data);
}
