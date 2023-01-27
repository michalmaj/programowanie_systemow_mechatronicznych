#include <iomanip>
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << std::setw(15) << std::left << (void*)this <<
            " Constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << std::setw(15) << std::left << (void*)this <<
            " Destructor called" << std::endl;
    }
};

int main() {

    std::cout << std::endl;

    std::unique_ptr<int> u_int(new int(17));
    std::cout << "*u_int: " << *u_int << std::endl;

    std::cout << std::endl;

    {
        std::unique_ptr<MyClass[]> myUniqueArray{ new MyClass[5] };
    }

    std::cout << std::endl;

    {
        std::unique_ptr<MyClass[]> myUniqueArray{ new MyClass[1] };
        MyClass myStruct;
        myUniqueArray[0] = myStruct;
    }

    std::cout << std::endl;

    {
        std::unique_ptr<MyClass[]> myUniqueArray{ new MyClass[1] };
        MyClass myStruct;
        myStruct = myUniqueArray[0];
    }

    std::cout << std::endl;
}