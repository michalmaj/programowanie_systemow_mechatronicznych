/*
 * Nale�y rozszerzy� poni�sz� klas� w taki spos�b, aby przelicza�a mile i stopy na metry.
 * Dodatkowo nale�y przeci��y� operator* w taki spos�b, aby pozwala� oblicza�, odleg�o��
 * pomno�on� przez jak�� warto��, na przyk�ad 4 * distance.
 */


#include <iostream>
#include <ostream>

namespace measure_distance
{
    class Distance
    {
    public:
        Distance(long double meter) :meters(meter)
        {}

        friend Distance operator+(const Distance& left, const Distance& right)
        {
            return { left.meters + right.meters };
        }
        friend Distance operator-(const Distance& left, const Distance& right)
        {
            return { left.meters - right.meters };
        }

        // Operator*
        friend Distance operator*(double n, const Distance& dist)
        {
            return { n * dist.meters };
        }

        friend std::ostream& operator<<(std::ostream& out, const Distance& dist)
        {
            out << dist.meters << " meters";
            return out;
        }
    private:
        long double meters;

    };

    namespace utility
    {
        // Operator dla mil
        Distance operator "" _mi(long double mile)
        {
            return { 1609.344 * mile };
        }
        // Operator dla stopy
        Distance operator "" _ft(long double feet)
        {
            return { 0.348 * feet };
        }
        Distance operator "" _km(long double kilometer)
        {
            return { 1000 * kilometer };
        }
        Distance operator "" _m(long double meter)
        {
            return { meter };
        }
        Distance operator "" _dm(long double decimeter)
        {
            return { decimeter / 10 };
        }
        Distance operator "" _cm(long double centimeter)
        {
            return { centimeter / 100 };
        }
    }
}

using namespace measure_distance::utility;

int main() {

    std::cout << std::endl;

    // U�ycie nowych operator�w
    std::cout << "1.0_mi: " << 1.0_mi << std::endl;
    std::cout << "1.0_ft " << 1.0_ft << std::endl;

    std::cout << "1.0_km: " << 1.0_km << std::endl;
    std::cout << "1.0_m: " << 1.0_m << std::endl;
    std::cout << "1.0_dm: " << 1.0_dm << std::endl;
    std::cout << "1.0_cm: " << 1.0_cm << std::endl;


    std::cout << std::endl;
    std::cout << "1.0_km + 2.0_dm +  3.0_dm - 4.0_cm: " << 1.0_km + 2.0_dm + 3.0_dm - 4.0_cm << std::endl;
    std::cout << std::endl;

    // Przyk�ad przeci��enia operatora*
    measure_distance::Distance distance_to_work = 45.0_km; // Odleg�o�� do pracy
    measure_distance::Distance number_of_rides = 2 * distance_to_work; // Ile razy w ci�gu dnia zostanie pokonana trasa z domu do pracy i z powrotem
    measure_distance::Distance shortcut = 2300.5_m; // O ile skraca si� trasa do pracy, je�li u�yje si� skr�tu
    measure_distance::Distance gym = 2 * 2100.0_m; // Odleg�o�� do si�owni w dwie strony
    measure_distance::Distance shop = 2 * 3876.0_m; // Odleg�o�� do sklepu i z powrotem

    measure_distance::Distance weekly = 5 * number_of_rides - 4 * shortcut + 2 * gym + shop;

    std::cout << "Distance per week: " << weekly << std::endl;

}