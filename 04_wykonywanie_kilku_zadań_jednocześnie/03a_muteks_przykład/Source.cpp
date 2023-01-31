#include <chrono>
#include <iostream>
#include <string_view>
#include <mutex>
#include <thread>

std::mutex mutex_cout;

class Worker {
public:
    Worker(std::string_view n) :name(n) {};

    void operator() () {
        for (int i = 1; i <= 3; ++i) {
            // Pocz¹tek pracy
            std::this_thread::sleep_for(
                std::chrono::milliseconds(200));
            // Koniec pracy
            mutex_cout.lock();
            std::cout << name << ": " << "Job " << i <<
                " done!" << std::endl;
            mutex_cout.unlock();
        }
    }
private:
    std::string name;
};


int main() {

    std::cout << std::endl;

    std::cout << "Start working." << "\n\n";

    std::thread john = std::thread(Worker("John"));
    std::thread arya = std::thread(Worker("Arya"));
    std::thread brienne = std::thread(Worker("Brienne"));
    std::thread dayne = std::thread(Worker("Dayne"));
    std::thread selemy = std::thread(Worker("Selemy"));
    std::thread jaime = std::thread(Worker("Jaime"));

    john.join();
    arya.join();
    brienne.join();
    dayne.join();
    selemy.join();
    jaime.join();

    std::cout << "\n" << "End working." << std::endl;

    std::cout << std::endl;

}