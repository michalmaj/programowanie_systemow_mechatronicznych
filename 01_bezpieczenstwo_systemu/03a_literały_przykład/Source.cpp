#include <iostream>
#include <ostream>

namespace measure_distance
{
    class Distance
	{
    public:
        Distance(long double meter) :meters(meter)
    	{}

        friend Distance operator+(const Distance& left, 
            const Distance& right)
    	{
            return {left.meters + right.meters};
        }
        friend Distance operator-(const Distance& left, 
            const Distance& right)
    	{
            return {left.meters - right.meters};
        }

        friend std::ostream& operator<<(std::ostream& out, 
            const Distance& dist)
    	{
            out << dist.meters << " meters";
            return out;
        }
    private:
        long double meters;

    };

    namespace utility
	{
        Distance operator "" _km(long double kilometer)
    	{
            return {1000 * kilometer};
        }
        Distance operator "" _m(long double meter)
    	{
            return {meter};
        }
        Distance operator "" _dm(long double decimeter)
    	{
            return {decimeter / 10};
        }
        Distance operator "" _cm(long double centimeter)
    	{
            return {centimeter / 100};
        }
    }
}

using namespace measure_distance::utility;

int main() {

    std::cout << std::endl;

    std::cout << "1.0_km: " << 1.0_km << std::endl;
    std::cout << "1.0_m: " << 1.0_m << std::endl;
    std::cout << "1.0_dm: " << 1.0_dm << std::endl;
    std::cout << "1.0_cm: " << 1.0_cm << std::endl;


    std::cout << std::endl;
    std::cout << "1.0_km + 2.0_dm +  3.0_dm - 4.0_cm: " << 
        1.0_km + 2.0_dm + 3.0_dm - 4.0_cm << std::endl;
    std::cout << std::endl;

}