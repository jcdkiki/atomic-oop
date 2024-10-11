#ifndef ATOMIC_OOP_RECORD_HPP_
#define ATOMIC_OOP_RECORD_HPP_

#include <string>
#include <stdexcept>
#include <iostream>

struct Record {
    int age;
    std::string name;
    std::string position;

    void setAge(int age)
    {
        if (age < 0) {
            throw std::invalid_argument("Age is below zero :(");
        }
        this->age = age;
    }

    bool setName(std::string name)
    {
        if (name.size() == 0) {
            return false;
        }

        this->name = name;
        return true;
    }
};

inline void PrintRecord(Record &r) {
    std::cout << r.name << " from '" << r.position << "'. " << r.age << " years old\n";
}


#endif
