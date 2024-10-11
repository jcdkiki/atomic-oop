#ifndef ATOMIC_OOP_CAR_HPP_
#define ATOMIC_OOP_CAR_HPP_

#include <stdexcept>
#include <iostream>

struct Car {
    int year;
    int min_rpm;
    int max_rpm;

    bool setYear(int year) {
        if (year < 0) {
            return false;
        } 

        this->year = year;
        return true;
    }

    void setMinRPM(int min_rpm) {
        if (min_rpm > max_rpm) {
            throw std::invalid_argument("Min RPM is bigger than Max RPM");
        }

        this->min_rpm = min_rpm;
    }

    void setMaxRPM(int max_rpm) {
        if (max_rpm < min_rpm) {
            throw std::invalid_argument("Max RPM is less than Min RPM");
        }

        this->max_rpm = max_rpm;
    }
};

inline void PrintCar(const Car &car)
{
    std::cout << car.year << " car [" << car.min_rpm << ", " << car.max_rpm << "]\n";
}

#endif
