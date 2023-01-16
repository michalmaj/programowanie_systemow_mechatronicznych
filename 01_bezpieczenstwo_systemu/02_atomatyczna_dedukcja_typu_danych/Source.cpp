#include <vector>

int add(int a, int b)
{
    return a + b;
}

int main() {

    // Definicja typu int
    int i = 5; // jawnie
    auto i1 = 5; // s³owo kluczowe auto

    // Definiowanie referencji na typ int
    int& b = i; // jawnie
    auto& b1 = i; // s³owo kluczowe auto

    // Definiowanie wskaŸnika na funkcjê
    int (*add_ptr)(int, int) = add; // jawnie
    auto add1 = add; // s³owo kluczowe auto

    // Iterator wektora
    std::vector<int> vec;
    // jawnie:
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {}
    // s³owo kluczowe auto
    for (auto it1 = vec.begin(); it1 != vec.end(); ++it1) {}

}