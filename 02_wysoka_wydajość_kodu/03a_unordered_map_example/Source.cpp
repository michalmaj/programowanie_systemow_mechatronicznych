#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main() {

    std::cout << std::endl;

    // std::map
    std::map<std::string, int> sorted_map{
    	{"John", 30}, {"Arya", 16}, {"Jaime", 45}, {"Brienne", 40}
    };
    for (auto p : sorted_map) 
        std::cout << '{' << p.first << ", " << p.second << '}';
    std::cout << std::endl;
    std::cout << "sorted_map[Jaime]: " << 
        sorted_map["Jaime"] << std::endl;
    sorted_map["Dayne"] = 37;
    sorted_map["Clegane"] = 51;
    for (auto p : sorted_map)
        std::cout << '{' << p.first << ", " << p.second << '}';

    std::cout << "\n\n";

    // std::unsorted_map
    std::unordered_map<std::string, int> unsorted_map{
    	{"John", 30}, {"Arya", 16}, {"Jaime", 45}, {"Brienne", 40} };
    for (auto p : unsorted_map) 
        std::cout << '{' << p.first << ", " << p.second << '}';
    std::cout << std::endl;
    std::cout << "unsorted_map[Jaime]: " <<
        unsorted_map["Jaime"] << std::endl;
    unsorted_map["Dayne"] = 37;
    unsorted_map["Clegane"] = 51;
    for (auto p : unsorted_map)
        std::cout << '{' << p.first << ", " << p.second << '}';

    std::cout << std::endl;
    std::cout << std::endl;
}