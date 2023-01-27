#include <iostream>
#include <string_view>
#include <memory>
#include <utility>

struct Name {

    Name(std::string_view name) : m_name(name) {}

    ~Name() {
        std::cout << "Destructor for: " << m_name << std::endl;
    }

    std::string m_name;

};


int main() {

    std::cout << std::endl;

    std::unique_ptr<Name> u_ptr1{ new Name("John") };

    std::cout << "u_ptr1.get(): " << u_ptr1.get() << std::endl;

    std::unique_ptr<Name> u_ptr2;
    u_ptr2 = std::move(u_ptr1);
    std::cout << "u_ptr1.get(): " << u_ptr1.get() << std::endl;
    std::cout << "u_ptr2.get(): " << u_ptr2.get() << std::endl;

    std::cout << std::endl;


    {
        std::unique_ptr<Name> u_ptr_local{ new Name("Jamie") };
    }

    std::cout << std::endl;

    u_ptr2.reset(new Name("Arya"));
    Name* my_name = u_ptr2.release();
    delete my_name;

    std::cout << std::endl;

    std::unique_ptr<Name> u_ptr3{ new Name("Hound") };
    std::unique_ptr<Name> u_ptr4{ new Name("Brynn") };

    std::cout << "u_ptr3.get(): " << u_ptr3.get() << std::endl;
    std::cout << "u_ptr4.get(): " << u_ptr4.get() << std::endl;

    std::swap(u_ptr3, u_ptr4);

    std::cout << "u_ptr3.get(): " << u_ptr3.get() << std::endl;
    std::cout << "u_ptr4.get(): " << u_ptr4.get() << std::endl;

    std::cout << std::endl;

}