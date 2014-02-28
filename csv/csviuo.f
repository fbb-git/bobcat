namespace FBB
{
    namespace IUO
    {
        enum CSVenum
        {
            INT,
            FLOAT,
            STRING
        };

        template <typename Type, typename ...TypeList>
        struct TypeCat;

        template <typename Type, typename Head, typename ...TypeList>
        struct TypeCat<Type, Head, TypeList...>
        {
            typedef typename TypeCat<Type, TypeList...>::type type;
            enum { cat = TypeCat<Type, TypeList...>::cat };
        };

        template <typename Type>
        struct TypeCat<Type>
        {
            typedef Type type;
            enum { cat = INT };
        };

        template <typename ...TypeList>
        struct TypeCat<float, float, TypeList...>
        {
            typedef float type;
            enum { cat = FLOAT };
        };

        template <typename ...TypeList>
        struct TypeCat<double, double, TypeList...>
        {
            typedef double type;
            enum { cat = FLOAT };
        };

        template <typename ...TypeList>
        struct TypeCat<long double, long double, TypeList...>
        {
            typedef long double type;
            enum { cat = FLOAT };
        };

        template <typename ...TypeList>
        struct TypeCat<std::string, std::string, TypeList...>
        {
            typedef std::string const &type;
            enum { cat = STRING };
        };

        template <typename Type>
        struct CSV
        {
            typedef typename 
            TypeCat<Type, float, double, long double, std::string>::type type;

            enum { 
                cat = 
                   TypeCat<Type, float, double, long double, std::string>::cat
            };
        };

        template <typename Type, size_t category>
        struct Avail
        {
            static Type get(std::string const &field);
        };

        template <typename Type>
        struct Avail<Type, FLOAT>
        {
            static Type get(std::string const &field);
        };

        template <typename Type>
        struct Avail<Type, STRING>
        {
            static Type get(std::string const &field);
        };

        template <typename Type>
        struct CSViteratorData
        {
            Type d_value;
        };

        template <>
        struct CSViteratorData<std::string>
        {
        };

    }   // IUO
} // FBB
