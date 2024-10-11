#ifndef ATOMIC_OOP_ATOMIC_CAR_HPP_
#define ATOMIC_OOP_ATOMIC_CAR_HPP_

#include <exception>
#include "car.hpp"
#include "atomic_change.hpp"

constexpr static KeyValueArgument<int> year("year");
constexpr static KeyValueArgument<int> min_rpm("min_rpm");
constexpr static KeyValueArgument<int> max_rpm("max_rpm");

inline bool SetKeyValue(Car &car, KeyValuePair<int> kv) {
    try {
        if (kv.key == "year") {
            if (!car.setYear(kv.value)) return false;
        }
        else if (kv.key == "min_rpm") {
            car.setMinRPM(kv.value);
        }
        else if (kv.key == "max_rpm") {
            car.setMaxRPM(kv.value);
        }
    }
    catch (std::exception &e) {
        return false;
    }
    return true;
}

#endif
