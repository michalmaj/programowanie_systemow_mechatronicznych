#include <iostream>
#include <thread>

void func_hello() {
    std::cout << "C++ in function." << std::endl;
}

class ClassHello {
public:
    void operator()() const {
        std::cout << "C++ in class." << std::endl;
    }
};

int main() {

    std::cout << std::endl;

    // W�tek wykonuje funkcj� func_hello()
    std::thread t1(func_hello);

    // W�tek wykonuje metod� z klasy ClassHello
    ClassHello obj_hello;
    std::thread t2(obj_hello);

    // W�tek wykonuje funkcj� lambda
    std::thread t3([] {std::cout <<
        "C++ in lambda." << std::endl; });

    // Nale�y si� upewni� czy w�tki t1, t2, t3
    // zako�czy�y prac� przed g��wnym w�tkiem
    t1.join();
    t2.detach();
    t3.join();

    std::cout << std::endl;

};