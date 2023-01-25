// Do przedstawionej poni¿ej klasy nale¿y dodaæ semantykê przenoszenia
// Nale¿y równie¿ okreœliæ czas potrzeby na wykonania przenoszenia


#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>


//class Container{
//
//public:
//    Container(size_t len): len_(len), data_(new int[len]){}
//
//    Container(const Container& other): len_(other.len_), data_(new int[other.len_]){
//        std::cout << "Copy construction of " << other.len_ << " elements "<< std::endl;
//        std::copy(other.data_, other.data_ + len_, data_);
//    }
//
//    Container& operator=(const Container& other){
//        std::cout << "Copy assignment of " << other.len_ << " elements "<< std::endl;
//        if (this != &other){
//            delete[] data_;
//
//            len_ = other.len_;
//            data_ = new int[len_];
//            std::copy(other.data_, other.data_ + len_, data_);
//        }
//        return *this;
//    }
//
//    Container(){
//        if(data_ != nullptr) delete[] data_;
//    }
//
//private:
//    size_t len_;
//    int* data_;
//};


class Container {

public:
    Container(size_t len) : len_(len), data_(new int[len]) {}

    explicit Container(const Container& other) : len_(other.len_), data_(new int[other.len_]) {
        std::cout << "Copy construction of " << other.len_ << " elements " << std::endl;
        std::copy(other.data_, other.data_ + len_, data_);
    }

    Container& operator=(const Container& other) {
        std::cout << "Copy assignment of " << other.len_ << " elements " << std::endl;
        if (this != &other) {
            delete[] data_;

            len_ = other.len_;
            data_ = new int[len_];
            std::copy(other.data_, other.data_ + len_, data_);
        }
        return *this;
    }

    Container(Container&& other) : len_(other.len_), data_(other.data_) {
        std::cout << "Move construction of " << other.len_ << " elements " << std::endl;
        other.len_ = 0;
        other.data_ = nullptr;
    }

    Container& operator=(Container&& other) {
        std::cout << "Move assignment of " << other.len_ << " elements " << std::endl;
        if (this != &other) {
            delete[] data_;

            len_ = other.len_;
            data_ = other.data_;

            other.data_ = nullptr;
            other.len_ = 0;
        }
        return *this;
    }

    ~Container() {
        if (data_ != nullptr) delete[] data_;
    }

private:
    size_t len_;
    int* data_;
};



int main() {

    std::cout << std::endl;

    std::vector<Container> vec;

    auto start = std::chrono::system_clock::now();

    vec.push_back(Container(1000000000));

    auto end = std::chrono::system_clock::now() - start;
    auto time_in_seconds = std::chrono::duration<double>(end).count();

    std::cout << std::endl;
    std::cout << "time in seconds: " << time_in_seconds << std::endl;
    std::cout << std::endl;

}