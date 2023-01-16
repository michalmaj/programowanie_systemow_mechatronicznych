/*
 * Prawid³owa inicjalizacja kontenerów z STL (array, vector, set, unordered_multiset)
 * za pomoc¹ nastêpuj¹cych wartoœci: -1, 10, 4, 2, 9, -3.
 */

#include <iostream>
 // Wczytanie odpowiednich kontenerów
#include <array>
#include <vector>
#include <set>
#include <unordered_set>

// Funkcja generyczna s³u¿¹ca do wyœwietlania kontenerów.
template <typename T>
void print(const T& collection)
{
    for (const auto& i : collection)
        std::cout << i << " ";
    std::cout << "\n\n";
}

int main() {

    std::cout << std::endl;

    // std::array ma sta³¹ iloœæ elementów (znan¹ w czasie kompilacji programu)
    std::array<int, 7> int_array = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_array);

    // Liczby ca³kowite nie s¹ wstawiane w kolejnoœci numerycznej (nie s¹ posortowane).
    std::vector<int> int_vector = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_vector);

    // Liczby ca³kowite s¹ wstawiane w kolejnoœci numerycznej (s¹ posortowane),
    // a zduplikowane elementy (w tym przypadku 4) nie s¹ wstawiane.
    std::set<int> int_set = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_set);

    // Klucze nie s¹ sortowane, a duplikaty kluczy s¹ dozwolone.
    std::unordered_multiset<int> int_unordered_set = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_unordered_set);

    std::cout << std::endl;

}
