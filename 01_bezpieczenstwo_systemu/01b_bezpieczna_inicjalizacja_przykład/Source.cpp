#include <initializer_list>
#include <iostream>
#include <string>

class DataConstruction {
public:

    DataConstruction(const std::string&, int) {
        std::cout << "DataConstruction(std::string, int)" << std::endl;
    }

    DataConstruction(int, int) {
        std::cout << "DataConstruction(int, int)" << std::endl;
    }

    DataConstruction(std::initializer_list<int>) {
        std::cout << "DataConstruction(std::initializer_list<int>)" << std::endl;
    }
};

template<typename T>
void printInitializerList(std::initializer_list<T> inList) {
    for (const auto& e : inList) std::cout << e << " ";
}

int main() {

    std::cout << std::endl;

    // Konstruktor sekwencji ma zawsze wy¿szy priorytet
    DataConstruction{ 1, 2 }; // std::initializer_list<int>

    // Zostanie wywo³any konstruktor z dwoma wartoœciami int
    DataConstruction(1, 2); // DataConstruction(int, int)

    // Zostanie wywo³any konstruktor z std::string i int
    DataConstruction{ "Some String", 2 };

    std::cout << std::endl;

    // Zostanie wyœwietlony inicjator listy zawieraj¹cy int-y
    printInitializerList({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });

    std::cout << std::endl;

}