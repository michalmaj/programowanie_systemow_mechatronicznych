#include <iostream>
#include <vector>

int func(int)
{
    return 2023;
}

int main() {

    auto int_var = 5; // Zwyk³a zmienna typu int
    auto& int_ref = int_var; // Referencja na int&
    auto* int_ptr = &int_var; // WskaŸnik na int*
    const auto const_int = int_var; // Sta³a const int
    static auto static_int = 10; // static int

    std::vector<int> int_vac;
    auto vec = int_vac; // Wektor intów std::vector<int>
    auto& vec_ref = vec; // Referencja std::vector<int>&

    int data[10];
    auto val1 = data; // WskaŸnik na int*
    auto& val2 = data; // Referencja int (&)[10]

    auto my_func = func; // Wykorzystanie auto do dedukcji (int)(*)(int)
    auto& my_func_ref = func; // Wykorzystanie auto do dedukcji (int)(&)(int)

    // Definiowanie wskaŸnika na funkcjê
    int (*my_add1)(int, int) = [](int a, int b) {return a + b; };

    // Definiowanie wskaŸnika na funkcjê za pomoc¹ auto
    auto my_add2 = [](int a, int b) {return a + b; };

    std::cout << "\n";

    // U¿ycie wskaŸnika na funkcjê (zwyk³a wersja)
    std::cout << "my_add2(1, 2) = " << my_add2(1, 2) << std::endl;

    // U¿ycie wskaŸnika na funkcjê (auto wersja)
    std::cout << "my_add2(1, 2) = " << my_add2(1, 2) << std::endl;

    std::cout << "\n";

}