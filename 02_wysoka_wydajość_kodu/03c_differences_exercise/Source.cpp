/*
 * Nale�y wykaza� podstawowe r�nice i podobie�stwa pomi�dzy:
 * std::unordered_multiset a std::unordered_set
 */

#include <iostream>
#include <set>
#include <unordered_set>

int main() {

    std::cout << std::endl;

    // Stworzenie obu kontener�w
    std::unordered_multiset<int> multi_set{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    std::unordered_set<int> unique_set(multi_set.begin(), multi_set.end());

    // P�tle po elementach poszczeg�lnych kontener�w
    std::cout << "multi_set: ";
    for (auto m : multi_set) std::cout << m << " ";

    std::cout << std::endl;

    std::cout << "unique_set: ";
    for (auto s : unique_set) std::cout << s << " ";

    std::cout << std::endl << std::endl;

    // Dodanie po jednym z element�w do ka�dej kolekcji
    multi_set.insert(-1000);
    unique_set.insert(-1000);

    // Stworzenie nowego std::set i dodanie go do istniej�cych kontener�w
    std::set<int> other_unique_set{ -5, -4, -3, -2, -1 };
    multi_set.insert(other_unique_set.begin(), other_unique_set.end());
    unique_set.insert(other_unique_set.begin(), other_unique_set.end());

    // P�tle po elementach poszczeg�lnych kontener�w
    std::cout << "multi_set: ";
    for (auto m : multi_set) std::cout << m << " ";

    std::cout << std::endl;

    std::cout << "unique_set: ";
    for (auto s : unique_set) std::cout << s << " ";

    std::cout << std::endl << std::endl;

    // Wyszukanie element�w
    auto it = unique_set.find(5);
    if (it != unique_set.end()) {
        std::cout << "unique_set.find(5): " << *it << std::endl;
    }

    std::cout << "multi_set.count(5): " << multi_set.count(5) << std::endl;

    std::cout << std::endl;

    // Usuni�cie wybranego elementu
    int numMulti = multi_set.erase(5);
    int numUniq = unique_set.erase(5);

    std::cout << "Erased " << numMulti << " times 5 from multi_set." << std::endl;
    std::cout << "Erased " << numUniq << " times 5 from unique_set." << std::endl;

    // Usuni�cie wszystkich element�w
    multi_set.clear();
    unique_set.clear();

    std::cout << std::endl;

    std::cout << "multi_set.size(): " << multi_set.size() << std::endl;
    std::cout << "unique_set.size(): " << unique_set.size() << std::endl;

    std::cout << std::endl;

}