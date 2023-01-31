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

    // W¹tek wykonuje funkcjê func_hello()
    std::thread t1(func_hello);

    // W¹tek wykonuje metodê z klasy ClassHello
    ClassHello obj_hello;
    std::thread t2(obj_hello);

    // W¹tek wykonuje funkcjê lambda
    std::thread t3([] {std::cout <<
        "C++ in lambda." << std::endl; });

    // Nale¿y siê upewniæ czy w¹tki t1, t2, t3
    // zakoñczy³y pracê przed g³ównym w¹tkiem
    t1.join();
    t2.detach();
    t3.join();

    std::cout << std::endl;

};