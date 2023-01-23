#include <iostream>

constexpr int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {

    std::cout << std::endl;

    constexpr int constexpr_var = gcd(11, 121);

    int a = 11;
    int b = 121;
    int var = gcd(a, b);

    std::cout << "gcd(11,121): " << constexpr_var << std::endl;
    std::cout << "gcd(a,b): " << var << std::endl;

    std::cout << std::endl;

}