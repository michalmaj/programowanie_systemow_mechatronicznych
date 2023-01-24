#include <iostream>
#include <map>
#include <unordered_map>

int main() {

    std::cout << std::endl;

    long long home = 497074123456;
    long long mobile = 4916046123356;

    // Budowanie std::unordered_multimap i std::unordered_map
    std::unordered_multimap<std::string, long long> multi_map{ {"grimm", home}, {"grimm", mobile}, {"jaud-grimm", home} };
    std::unordered_map<std::string, int> unique_map{ {"bin", 1}, {"root", 20}, {"nobody", 65834}, {"rainer", 1000} };

    // Wyœwietlenie multi mapy
    std::cout << "multi_map: ";
    for (auto m : multi_map) std::cout << '{' << m.first << ", " << m.second << '}';

    std::cout << std::endl;

    std::cout << "unique_map: ";
    for (auto u : unique_map) std::cout << '{' << u.first << ", " << u.second << '}';
    std::cout << std::endl;

    std::cout << std::endl;

    // dodanie elementu
    long long work = 4970719754513;

    multi_map.insert({ "grimm", work });

    // Tylko metoda insert zadzia³a
    //multi_map["grimm-jaud"]=4916012323356;

    unique_map["lp"] = 4;
    unique_map.insert({ "sshd", 71 });

    std::map<std::string, int> myMap{ {"ftp", 40}, {"rainer", 999} };
    unique_map.insert(myMap.begin(), myMap.end());

    // Wyœwietlenie multi mapy
    std::cout << "multi_map: ";
    for (auto m : multi_map) std::cout << '{' << m.first << ", " << m.second << '}';

    std::cout << std::endl;

    std::cout << "unique_map: ";
    for (auto u : unique_map) std::cout << '{' << u.first << ", " << u.second << '}';
    std::cout << std::endl;


    std::cout << std::endl;

    // Szukanie elementu
    auto iter = multi_map.equal_range("grimm");
    std::cout << "grimm: ";
    for (auto itVal = iter.first; itVal != iter.second; ++itVal) {
        std::cout << itVal->second << " ";
    }

    std::cout << std::endl;

    std::cout << "multi_map.count(grimm): " << multi_map.count("grimm") << std::endl;

    auto it = unique_map.find("root");
    if (it != unique_map.end()) {
        std::cout << "unique_map.find(root): " << it->second << std::endl;
        std::cout << "unique_map[root]: " << unique_map["root"] << std::endl;
    }

    // Sprawdzenie, czy element jest w mapie
    std::cout << "unique_map[notAvailable]: " << unique_map["notAvailable"] << std::endl;

    std::cout << std::endl;

    // Usuniêcie wybranego klucza
    int numMulti = multi_map.erase("grimm");
    int numUniq = unique_map.erase("rainer");

    std::cout << "Erased " << numMulti << " times grimm from multi_map." << std::endl;
    std::cout << "Erased " << numUniq << " times rainer from unique_map." << std::endl;

    // Usuniêcie wszystkiego
    multi_map.clear();
    unique_map.clear();

    std::cout << std::endl;

    std::cout << "multi_map.size(): " << multi_map.size() << std::endl;
    std::cout << "unique_map.size(): " << unique_map.size() << std::endl;

    std::cout << std::endl;

}