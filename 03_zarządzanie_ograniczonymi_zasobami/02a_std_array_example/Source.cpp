#include <algorithm>
#include <array>
#include <iostream>

int main() {

    std::cout << std::endl;

    // Wyœwietli zawartoœæ std::array
    std::array <int, 8> arr{ 1, 2, 3, 4, 5, 6, 7, 8 };
    std::for_each(arr.begin(), arr.end(),
        [](int value) {std::cout << value << " "; });

    std::cout << std::endl;

    // Oblicza sumê elementów w std::array
    int sum = 0;
    std::for_each(arr.begin(), arr.end(), 
        [&sum](int value) { sum += value; });
    std::cout << "sum of array{1,2,3,4,5,6,7,8}: " <<
        sum << std::endl;

    // Podnosi ka¿d¹ wartoœæ w kontenerze do drugiej potêgi
    std::for_each(arr.begin(), arr.end(), 
        [](int& value) { value = value * value; });

    // Wyœwietli zawartoœæ std::array po potêgowaniu
	std::for_each(arr.begin(), arr.end(), 
        [](int value) {std::cout << value << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
}