#include <algorithm>
#include <array>
#include <iostream>

int main() {

    std::cout << std::endl;

    // Wy�wietli zawarto�� std::array
    std::array <int, 8> arr{ 1, 2, 3, 4, 5, 6, 7, 8 };
    std::for_each(arr.begin(), arr.end(),
        [](int value) {std::cout << value << " "; });

    std::cout << std::endl;

    // Oblicza sum� element�w w std::array
    int sum = 0;
    std::for_each(arr.begin(), arr.end(), 
        [&sum](int value) { sum += value; });
    std::cout << "sum of array{1,2,3,4,5,6,7,8}: " <<
        sum << std::endl;

    // Podnosi ka�d� warto�� w kontenerze do drugiej pot�gi
    std::for_each(arr.begin(), arr.end(), 
        [](int& value) { value = value * value; });

    // Wy�wietli zawarto�� std::array po pot�gowaniu
	std::for_each(arr.begin(), arr.end(), 
        [](int value) {std::cout << value << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
}