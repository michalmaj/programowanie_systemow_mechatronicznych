#include <chrono>
#include <future>
#include <map>
#include <string>
#include <tuple>

int main() {

    auto my_ints = { 1, 2, 3 };
    auto my_int_ptr = my_ints.begin();

    std::map<int, std::string> my_map = { {1, std::string("four")}, {2, std::string("five")} };
    auto my_map_begin = my_map.begin();

    auto func = [](const std::string& a) { return a; };

    auto async_lambda = std::async([] { return std::string("Hello World"); });

    auto start_timer = std::chrono::system_clock::now();

    auto pair = std::make_pair(1, std::string("one"));

    auto tuple = std::make_tuple(std::string("Hello World"), 4.13f, 1, 22.16, false, 'z');

}