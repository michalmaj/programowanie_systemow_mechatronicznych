// Nale¿y zast¹piæ w poni¿szym kodzie s³owo kluczowe auto, jawnym typem
/*
auto my_ints = { 1, 2, 3 };
auto my_int_ptr = my_ints.begin();

std::map<int, std::string> my_map = {
        {1, std::string("four")}, {2, std::string("five")}
};
auto my_map_begin = my_map.begin();

auto func = [](const std::string& a)
{
    return a;
};

auto async_lambda = std::async([]
                               { return std::string("Hello World"); });

auto start_timer = std::chrono::system_clock::now();

auto pair = std::make_pair(1, std::string("one"));

auto tuple = std::make_tuple(std::string("Hello World"),
                             4.13f, 1, 22.16, false, 'z');
*/

#include <chrono>
#include <future>
#include <map>
#include <string>
#include <tuple>

// Nale¿y dodaæ nastêpuj¹ce biblioteki
#include <functional>
#include <future>

int main() {

    std::initializer_list<int> my_ints = { 1, 2, 3 };
    std::initializer_list<int>::iterator my_int_ptr = my_ints.begin();

    std::map<int, std::string> my_map = { {1, std::string("four")}, {2, std::string("five")} };
    std::map<int, std::string>::iterator my_map_begin = my_map.begin();

    std::function<std::string(const std::string&)> func = [](const std::string& a) { return a; };

    std::future<std::string> async_lambda = std::async([] { return std::string("Hello World"); });

    std::chrono::time_point<std::chrono::system_clock> start_timer = std::chrono::system_clock::now();

    std::pair<int, std::string> pair = std::make_pair(1, std::string("one"));

    std::tuple<std::string, float, int, double, bool, char> tuple = std::make_tuple(std::string("Hello World"), 4.13f, 1, 22.16, false, 'z');

}