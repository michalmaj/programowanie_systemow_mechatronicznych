/*
 * U�ywaj�c biblioteki type_traits, nale�y przebada�, modyfikuj�c w czasie trwania kompilacji typ danych int:
 *  1. Doda� s�owo kluczowe const (std::add_const).
 *  2. Usun�� s�owo kluczowe const (std::remove_const).
 *  3. Por�wna� ze sob� cont int oraz std::add_const.
 */

#include <iostream>
#include <type_traits>

int main()
{

    std::cout << std::boolalpha << std::endl;

    std::cout << "std::is_const<std::add_const<int>::type>::value: " << std::is_const<std::add_const<int>::type>::value << std::endl;
    std::cout << "std::is_const<std::remove_const<const int>::type>::value: " << std::is_const<std::remove_const<const int>::type>::value << std::endl;

    std::cout << std::endl;
    using my_const_int = std::add_const<int>::type;
    std::cout << "std::is_const<my_const_int>::value: " << std::is_const<my_const_int>::value << std::endl;
    using my_const_int2 = const int;
    std::cout << "std::is_same<my_const_int, my_const_int2>::value: " << std::is_same<my_const_int, my_const_int2>::value << std::endl;

    std::cout << std::endl;
}