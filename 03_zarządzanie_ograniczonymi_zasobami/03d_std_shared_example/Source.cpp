#include <iostream>
#include <string_view>
#include <memory>

using std::shared_ptr;

struct Names {
    Names(std::string_view name) : m_name(name) {
        std::cout << "Constructor called for: " <<
            m_name << std::endl;
    }
    ~Names() {
        std::cout << "Destructor called for: " <<
            m_name << std::endl;
    }
    std::string m_name;
};

int main() {

    std::cout << std::endl;

    shared_ptr<Names> s_ptr(new Names("John"));
    std::cout << "My name: " << s_ptr->m_name << std::endl;
    std::cout << "s_ptr.use_count(): " <<
        s_ptr.use_count() << std::endl;


    {
        shared_ptr<Names> s_ptr_local(s_ptr);
        std::cout << "s_ptr_local.use_count(): " << 
            s_ptr_local.use_count() << std::endl;
    }
    std::cout << "s_ptr.use_count(): " <<
        s_ptr.use_count() << std::endl;

    shared_ptr<Names> s_ptr_global = s_ptr;
    std::cout << "s_ptr.use_count(): " <<
        s_ptr.use_count() << std::endl;

    s_ptr_global.reset();

    std::cout << "s_ptr.use_count(): " << 
        s_ptr.use_count() << std::endl;

    s_ptr = shared_ptr<Names>(new Names("Arya"));

    std::cout << std::endl;
}