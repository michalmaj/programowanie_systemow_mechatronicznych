#include <cstring>
#include <chrono>
#include <iostream>
#include <type_traits>

namespace fill_array
{

    template <typename Type1, typename Type2, bool b>
    void my_fill(Type1 first, Type1 last, 
        const Type2& val, const std::integral_constant<bool, b>&)
	{
        while (first != last) {
            *first = val;
            ++first;
        }
    }

    template <typename Type>
    void my_fill(Type* first, Type* last, 
        const Type& val, const std::true_type&)
	{
        std::memset(first, val, last - first);
    }

    template <class Type1, class Type2>
    inline void fill(Type1 first, Type1 last, const Type2& val)
	{
        typedef std::integral_constant<bool,
    	std::is_trivially_copy_assignable<Type2>::value &&
            (sizeof(Type2) == 1)> boolType;
        my_fill(first, last, val, boolType());
    }
}

const int SIZE = 100000000;
char char_array1[SIZE] = { 0, };
char char_array2[SIZE] = { 0, };

int main()
{

    std::cout << std::endl;

    auto start = std::chrono::system_clock::now();
    fill_array::fill(char_array1, char_array1 + SIZE, 1);
    auto stop = 
        std::chrono::system_clock::now() - start;
    std::cout << "char_array1: " << 
        std::chrono::duration<double>(stop).count() << " seconds" << std::endl;

    start = std::chrono::system_clock::now();
    fill_array::fill(char_array2, char_array2 + SIZE,
        static_cast<char>(1));
    stop = std::chrono::system_clock::now() - start;
    std::cout << "char_array2: "
	<< std::chrono::duration<double>(stop).count() <<
        " seconds" << std::endl;

    std::cout << std::endl;

}