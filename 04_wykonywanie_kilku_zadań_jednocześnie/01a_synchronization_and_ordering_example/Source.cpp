#include <atomic>
#include <iostream>
#include <thread>

struct AtomicHelper
{
	std::atomic_int x;
	std::atomic_int y;
	int r1;
	int r2;
};

void writeX(void* param) {
	auto ah = static_cast<AtomicHelper*>(param);
	ah->x.store(1);
	ah->r1 = ah->y.load();
}

void writeY(void* param) {
	auto ah = static_cast<AtomicHelper*>(param);
	ah->y.store(1);
	ah->r2 = ah->x.load();
}

int main() {

	AtomicHelper ah;
	std::cout << std::endl;

	ah.x = 0;
	ah.y = 0;
	std::thread a(writeX, &ah);
	std::thread b(writeY, &ah);
	a.join();
	b.join();
	std::cout << "(r1, r2) = " <<
		"(" << ah.r1 << ", " << ah.r2 << ")" << std::endl;

	std::cout << std::endl;

}

