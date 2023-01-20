#include <iostream>
#include <type_traits>


union MyUnion {
    int var;
};

enum class MyEnum {
    var = 1,
};

struct MyStructure {
    int var;
    int my_method(double) { return 16; }
};

int main() {

    std::cout << std::endl;
    std::cout << std::boolalpha;

    // W³asne typy danych
    std::cout << "is_union<MyUnion>::value: " <<
        std::is_union<MyUnion>::value << std::endl;
    std::cout << "is_enum<MyEnum>::value: " <<
        std::is_enum<MyEnum>::value << std::endl;
    std::cout <<
        "is_member_object_pointer<int MyStructure::*>::value: " <<
        std::is_member_object_pointer<int MyStructure::*>::value <<
        std::endl;
    std::cout <<
        "is_member_function_pointer<int (MyStructure::*)(double)>::value: " <<
        std::is_member_function_pointer<int (MyStructure::*)(double)>::value <<
        std::endl;

    // Podstawowe typy danych
    std::cout << "is_void<void>::value: " <<
        std::is_void<void>::value << std::endl;
    std::cout << "is_integral<short>::value: " << 
        std::is_integral<short>::value << std::endl;
    std::cout << "is_floating_point<double>::value: " <<
        std::is_floating_point<double>::value << std::endl;
    std::cout << "is_array<int []>::value: " <<
        std::is_array<int[] >::value << std::endl;
    std::cout << "is_pointer<int*>::value: " <<
        std::is_pointer<int*>::value << std::endl;
    std::cout << "is_null_pointer<std::nullptr_t>::value: " <<
        std::is_null_pointer<std::nullptr_t>::value << std::endl;

    // Z³o¿one typy danych
    std::cout << "is_class<string>::value: " <<
        std::is_class<std::string>::value << std::endl;
    std::cout << "is_function<int * (double)>::value: " <<
        std::is_function<int* (double)>::value << std::endl;
    std::cout << "is_lvalue_reference<int&>::value: " <<
        std::is_lvalue_reference<int&>::value << std::endl;
    std::cout << "is_rvalue_reference<int&&>::value: " <<
        std::is_rvalue_reference<int&&>::value << std::endl;

    std::cout << std::endl;

}