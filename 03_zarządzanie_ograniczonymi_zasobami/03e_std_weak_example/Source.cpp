#include <iostream>
#include <memory>

int main() {

    std::cout << std::boolalpha << std::endl;

    auto s_ptr1 = std::make_shared<int>(2077);
    std::weak_ptr<int> w_ptr(s_ptr1);

    std::cout << "w_ptr.use_count(): " << 
        w_ptr.use_count() << std::endl;

    std::cout << "s_ptr1.use_count(): " << 
        s_ptr1.use_count() << std::endl;

    std::cout << "w_ptr.expired(): " << 
        w_ptr.expired() << std::endl;

    if (std::shared_ptr<int> s_ptr2 = w_ptr.lock()) {
        std::cout << "*s_ptr1: " << *s_ptr1 << std::endl;
        std::cout << "s_ptr2.use_count(): " << 
            s_ptr2.use_count() << std::endl;
    }
    else {
        std::cout << "Don't get the resource!" << std::endl;
    }

    w_ptr.reset();
    if (std::shared_ptr<int> s_ptr2 = w_ptr.lock()) {
        std::cout << "*s_ptr1: " << *s_ptr1 << std::endl;
        std::cout << "s_ptr2.use_count(): " <<
            s_ptr2.use_count() << std::endl;
    }
    else {
        std::cout << "Don't get the resource!" << std::endl;
    }

    std::cout << std::endl;

}