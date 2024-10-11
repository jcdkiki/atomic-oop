#ifndef ATOMIC_OOP_ATOMIC_RECORD_HPP_
#define ATOMIC_OOP_ATOMIC_RECORD_HPP_

#include <exception>
#include "record.hpp"
#include "atomic_change.hpp"

constexpr static KeyValueArgument<std::string> name("name");
constexpr static KeyValueArgument<std::string> position("position");
constexpr static KeyValueArgument<int> age("age");

inline bool SetKeyValue(Record &record, KeyValuePair<std::string> kv) {
    if (kv.key == "name") {
        if (!record.setName(kv.value))
            return false;
    }
    else if (kv.key == "position") {
        record.position = kv.value;
    }
    return true;
}

inline bool SetKeyValue(Record &record, KeyValuePair<int> kv) {
    try {
        if (kv.key == "age") {
            record.setAge(kv.value);
        }
    }
    catch (std::exception &e) {
        return false;
    }
    return true;
}

#endif
