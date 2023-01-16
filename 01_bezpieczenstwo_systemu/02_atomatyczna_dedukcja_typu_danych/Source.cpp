#include <iostream>
#include <string>

struct MyStruct1 {};

struct MyStruct2 {
    int int_var;     // Zmienna nie posiada inicjalizacji
public:
    MyStruct2() {}
};

int n;          //  W tym przypadku n = 0

int main() {

    std::cout << std::endl;

    int n; // Zmienna nie posiada inicjalizacji
    std::string s; // Zmienna zostanie zainicjalizowana jako "", ze wzgl�du na konstruktor
    MyStruct1 my_struct1; // Wywo�any zostanie konstruktor domy�lny
    MyStruct2 my_struct2; // Wywo�any zostanie konstruktor domy�lny

    std::cout << "::n " << ::n << std::endl; // 0
    std::cout << "n: " << n << std::endl; // �mieci z pami�ci
    std::cout << "s: " << s << std::endl; // Pusty string
    std::cout << "MyStruct2().int_var: " << MyStruct2().int_var << std::endl; // 0

    std::cout << std::endl;

}