#include <iostream>

int main() {

    // Inicjalizacja za pomoc¹ = lub () nie spowoduje b³êdu
    char c1(999);
    char c2 = 999;
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;

    int i1(3.14);
    int i2 = 3.14;
    std::cout << "i1: " << i1 << std::endl;
    std::cout << "i2: " << i2 << std::endl;

    //    // Natomiast u¿ycie {} spowoduje b³¹d kompilacji
    //    char c1{ 999 }; // Spowoduje b³¹d [-128, 127]
    //    char c2 = { 999 }; // Spowoduje b³¹d [-128, 127]
    //    std::cout << "c1: " << c1 << std::endl;
    //    std::cout << "c2: " << c2 << std::endl;
    //
    //    int i1{ 3.14 }; // Spowoduje b³¹d (int nie mo¿e byæ zmiennoprzecinkowy)
    //    int i2 = { 3.14 };
    //    std::cout << "i1: " << i1 << std::endl;
    //    std::cout << "i2: " << i2 << std::endl;
    //
    //    char c3{ 8 };
    //    std::cout << "c3: " << c3 << std::endl;

}