#include <iostream>
#include <vector>


template <typename T>
void swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

struct UserData {
    std::vector<int> userData;

    UserData() : userData({ 1, 2, 3, 4, 5 }) {}

    // Konstruktor kopiowania
    UserData(const UserData& m) : userData(m.userData) {
        std::cout << "copy constructor" << std::endl;
    }

    // Operator kopiowania
    UserData& operator=(const UserData& m) {
        userData = m.userData;
        std::cout << "copy assignment operator" << std::endl;
        return *this;
    }

};

int main() {

    std::cout << std::endl;

    UserData a, b;
    swap(a, b);
};