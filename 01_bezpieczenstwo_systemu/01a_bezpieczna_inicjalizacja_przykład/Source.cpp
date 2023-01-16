#include <map>
#include <vector>
#include <string>

// Przygotowanie kontenera, w którym znajduje siê tablica w stylu C zawieraj¹ca 5 elementów
class Container {
public:
    Container() : m_data{ 1,2,3,4,5 } {}
private:
    int m_data[5];
};

class MyClass {
public:
    int m_x;
    double m_y;
};

class MyClass2 {
public:
    MyClass2(int x, double y) :m_x{ x }, m_y{ y } {};
private:
    int m_x;
    double m_y;
};

int main() {

    // Inicjalizacja tablicy
    int intArray[] = { 1,2,3,4,5 };
    std::vector<int> intArray1{ 1,2,3,4,5 };
    std::map<std::string, int> myMap{ {"John", 76}, {"Arya",72} };

    // Utworzenie i inicjalizacja tablicy na stercie
    const float* ptrData = new const float[3] {1.1, 2.2, 3.3};

    Container arr;

    // Inicjalizacja ró¿nych typów danych
    int i{};                // Zostanie przypisana wartoœæ 0
    std::string s{};        // Zostanie przypisana wartoœæ ""
    std::vector<float> v{}; // Wektor bêdzie pusty
    double d{};             // // Zostanie przypisana wartoœæ 0.0

    // Incjalizacja obiektu klasy
    MyClass myClass{ 2011,3.14 };
    MyClass myClass1 = { 2011,3.14 };

    // Incjalizacja obiektu klasy przy pomocy konstruktora
    MyClass2 myClass2{ 2011,3.14 };
    MyClass2 myClass3 = { 2011,3.14 };

}