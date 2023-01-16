/*
 * Prawid�owa inicjalizacja kontener�w z STL (array, vector, set, unordered_multiset)
 * za pomoc� nast�puj�cych warto�ci: -1, 10, 4, 2, 9, -3.
 */

#include <iostream>
 // Wczytanie odpowiednich kontener�w
#include <array>
#include <vector>
#include <set>
#include <unordered_set>

// Funkcja generyczna s�u��ca do wy�wietlania kontener�w.
template <typename T>
void print(const T& collection)
{
    for (const auto& i : collection)
        std::cout << i << " ";
    std::cout << "\n\n";
}

int main() {

    std::cout << std::endl;

    // std::array ma sta�� ilo�� element�w (znan� w czasie kompilacji programu)
    std::array<int, 7> int_array = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_array);

    // Liczby ca�kowite nie s� wstawiane w kolejno�ci numerycznej (nie s� posortowane).
    std::vector<int> int_vector = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_vector);

    // Liczby ca�kowite s� wstawiane w kolejno�ci numerycznej (s� posortowane),
    // a zduplikowane elementy (w tym przypadku 4) nie s� wstawiane.
    std::set<int> int_set = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_set);

    // Klucze nie s� sortowane, a duplikaty kluczy s� dozwolone.
    std::unordered_multiset<int> int_unordered_set = { -1, 10, 4, 2, 9, -3, 4 };
    print(int_unordered_set);

    std::cout << std::endl;

}
