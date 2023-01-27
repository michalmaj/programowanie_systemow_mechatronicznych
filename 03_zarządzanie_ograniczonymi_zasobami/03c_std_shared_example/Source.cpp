#include <iostream>
#include <memory>

class SharePtr : public std::enable_shared_from_this<SharePtr>
{
public:
    std::shared_ptr<SharePtr> getShared() {
        return shared_from_this();
    }
};

int main()
{

    std::cout << std::endl;

    std::shared_ptr<SharePtr> share_ptr1(new SharePtr);
    std::shared_ptr<SharePtr> share_ptr2 = share_ptr1->getShared();

    std::cout << "share_ptr1.get(): " << 
        share_ptr1.get() << std::endl;

    std::cout << "share_ptr2.get(): " << 
        share_ptr2.get() << std::endl;

    {
        auto share_ptr3(share_ptr2);
        std::cout << "share_ptr1.use_count(): " <<
            share_ptr1.use_count() << std::endl;
    }
    std::cout << "share_ptr1.use_count(): " << 
        share_ptr1.use_count() << std::endl;

    share_ptr2.reset();

    std::cout << "share_ptr1.use_count(): " << 
        share_ptr1.use_count() << std::endl;

    std::cout << std::endl;

}