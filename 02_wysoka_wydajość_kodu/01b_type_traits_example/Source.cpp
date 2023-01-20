#include <iostream>
#include <type_traits>
#include <typeinfo>

template<typename Type1, typename Type2>
typename std::conditional <(sizeof(Type1) < 
    sizeof(Type2)), Type1, Type2>::type gcd(Type1 a, Type2 b) {
    static_assert(std::is_integral<Type1>::value,
        "Type1 should be an integral type!");
    static_assert(std::is_integral<Type2>::value,
        "Type2 should be an integral type!");
    if (b == 0) { return a; }
    else {
        return gcd(b, a % b);
    }
}

int main() {

    std::cout << std::endl;

    std::cout << "gcd(52,6)= " << gcd(52, 6) << std::endl;
    std::cout << "gcd(999, 18)= " << gcd(999, 18) << std::endl;
    std::cout << "gcd(42, 56)= " << gcd(42, 56) << std::endl;

    std::cout << std::endl;

    std::cout << "gcd(100,10LL)= " << gcd(100, 10LL) << std::endl;

    std::conditional <(sizeof(100) < 
        sizeof(10LL)), long long, long>::type uglyRes = gcd(100, 10LL);
    auto res = gcd(100, 10LL);
    auto res2 = gcd(100LL, 10L);

    std::cout << "typeid(gcd(100,10LL)).name(): " <<
        typeid(res).name() << std::endl;
    std::cout << "typeid(gcd(100LL,10L)).name(): " <<
        typeid(res2).name() << std::endl;

    std::cout << std::endl;

}