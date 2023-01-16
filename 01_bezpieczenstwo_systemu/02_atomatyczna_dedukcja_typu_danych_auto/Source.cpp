#include <iostream>
#include <string>

struct MyStruct1 {};

struct MyStruct2 {
    int int_var{};
public:
    MyStruct2() {}
};

auto n{ 0 };

using namespace std::string_literals;

int main() {

    std::cout << std::endl;

    auto n{ 0 };
    std::string s = ""s;
    auto my_struct1 = MyStruct1();
    auto my_struct2 = MyStruct2();

    std::cout << "::n " << ::n << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "s: " << s << std::endl;
    std::cout << "MyStruct2().int_var: " << MyStruct2().int_var << std::endl;

    std::cout << std::endl;

}