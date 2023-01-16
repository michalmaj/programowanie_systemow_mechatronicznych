#include <iostream>
#include <vector>

int func(int)
{
    return 2023;
}

int main() {

    auto int_var = 5; // Zwyk�a zmienna typu int
    auto& int_ref = int_var; // Referencja na int&
    auto* int_ptr = &int_var; // Wska�nik na int*
    const auto const_int = int_var; // Sta�a const int
    static auto static_int = 10; // static int

    std::vector<int> int_vac;
    auto vec = int_vac; // Wektor int�w std::vector<int>
    auto& vec_ref = vec; // Referencja std::vector<int>&

    int data[10];
    auto val1 = data; // Wska�nik na int*
    auto& val2 = data; // Referencja int (&)[10]

    auto my_func = func; // Wykorzystanie auto do dedukcji (int)(*)(int)
    auto& my_func_ref = func; // Wykorzystanie auto do dedukcji (int)(&)(int)

    // Definiowanie wska�nika na funkcj�
    int (*my_add1)(int, int) = [](int a, int b) {return a + b; };

    // Definiowanie wska�nika na funkcj� za pomoc� auto
    auto my_add2 = [](int a, int b) {return a + b; };

    std::cout << "\n";

    // U�ycie wska�nika na funkcj� (zwyk�a wersja)
    std::cout << "my_add2(1, 2) = " << my_add2(1, 2) << std::endl;

    // U�ycie wska�nika na funkcj� (auto wersja)
    std::cout << "my_add2(1, 2) = " << my_add2(1, 2) << std::endl;

    std::cout << "\n";

}