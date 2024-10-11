#include <cstring>
#include <iostream>

#include "record.hpp"
#include "atomic_record.hpp"
#include "car.hpp"
#include "atomic_car.hpp"

int main() {
    Record record{20, "Joe Peach", "USA"};
    PrintRecord(record);

    // Valid
    std::cout << AtomicChange(record)(age = 30, name = "Boris", position = "Russia") << '\n';
    PrintRecord(record);

    // Empty position is still valid
    std::cout << AtomicChange(record)(position = "", age = 40) << '\n';
    PrintRecord(record);

    // Invalid name
    std::cout << AtomicChange(record)(name = "", position = "Canada", age = 50) << '\n';
    PrintRecord(record);

    // Invalid age
    std::cout << AtomicChange(record)(name = "Barack", position = "Africa", age = -10) << '\n';
    PrintRecord(record);

    std::cout << AtomicChange(record)(position = "Japan") << '\n';
    PrintRecord(record);

    // Valid
    std::cout << AtomicChange(record)(position = "Russia", name = "John Doe", age = 54) << '\n';
    PrintRecord(record);

    // CAR EXAMPLE
    Car car{ 1998, 800, 5000 };
    PrintCar(car);

    std::cout << AtomicChange(car)(min_rpm = 9000) << '\n';
    PrintCar(car);

    std::cout << AtomicChange(car)(min_rpm = 1200) << '\n';
    PrintCar(car);

    std::cout << AtomicChange(car)(year = 2020, min_rpm = 1000, max_rpm = 900) << '\n';
    PrintCar(car);

    std::cout << AtomicChange(car)(year = 2022, min_rpm = 500, max_rpm = 900) << '\n';
    PrintCar(car);
}
