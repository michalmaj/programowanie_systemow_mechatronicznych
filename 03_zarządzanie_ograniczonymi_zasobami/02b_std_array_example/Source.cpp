#include <array>
#include <iostream>

int main() {

    std::cout << std::endl;

    std::array<int, 4> arr = { 1, 2, 3, 4 };

    for (auto a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    arr[0] = 1000;
    arr[2] = 5;

    for (auto a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    arr.at(0) = '2';
    arr.at(2) = 'c';

    for (auto a : arr) { std::cout << a << " "; }
    std::cout << std::endl;

    arr.at(100) = 'l';
}