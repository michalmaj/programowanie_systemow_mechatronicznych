#include <iostream>
#include <string>
#include <utility>

int main() {

    std::string str1{ "ABCDEF" };
    std::string str2;

    std::cout << "\n";

    // Wyœwietlenie aktualnych wartoœci
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    // Kopiowanie
    str2 = str1;
    std::cout << "str2 = str1;\n";
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    std::cout << "\n";

    std::string str3;

    // Wyœwietlenie aktualnych wartoœci
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str3 = " << str3 << std::endl;

    // U¿ycie std::move
    str3 = std::move(str1);
    std::cout << "str3 = std::move(str1);\n";
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str3 = " << str3 << std::endl;
}