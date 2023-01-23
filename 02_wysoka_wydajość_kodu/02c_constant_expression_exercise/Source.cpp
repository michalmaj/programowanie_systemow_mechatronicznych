/*
 * Sprawdziæ dzia³anie obiektu z constexpr i bez niego.
 */

#include <iostream>

struct MyDoubleVal {
	double myVal;
	constexpr MyDoubleVal(double v) : myVal(v) {}
	constexpr double get_val() const { return myVal; }
};
int main() {
	
	MyDoubleVal val1{10};
	std::cout << "val1: " << val1.get_val() << std::endl;

	constexpr MyDoubleVal val2{ 10 }; // Wymaga, ¿eby get_val() by³o oznaczone jako const
	std::cout << "val2: " << val2.get_val() << std::endl;


	return 0;
}