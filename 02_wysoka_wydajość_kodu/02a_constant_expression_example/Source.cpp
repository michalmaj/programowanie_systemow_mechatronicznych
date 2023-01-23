#include <iostream>

constexpr int square(int x)
{
	return x * x;
}
constexpr int square2square(int x)
{
	return square(square(x));
}

int main() {

	std::cout << std::endl;

	int a = 10;
	//static_assert(square(a) == 100,
	//	"Wrong calculations");
	//static_assert(square2square(10) == 10000,
	//	"Wrong calculations");

	std::cout << "square(10)= " << square(10) << std::endl;
	std::cout << "square2square(10)= " <<
		square2square(10) << std::endl;

	constexpr int const_expr = square(10);

	int c_array[100];
	int c_array_constexpr[const_expr];
	int c_array_constexpr_function[square(10)];

	std::cout << std::endl;

}