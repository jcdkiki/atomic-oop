#ifndef ATOMIC_OOP_ATOMC_CHANGE_HPP_
#define ATOMIC_OOP_ATOMC_CHANGE_HPP_

#include <string_view>

template <class ValueType> struct KeyValuePair {
    std::string_view key;
    ValueType value;
};

template <typename ValueType> struct KeyValueArgument {
    const char *key;
    constexpr KeyValueArgument(const char *key) : key(key) {}

    template <typename T> KeyValuePair<ValueType> operator=(T value) const {
        return KeyValuePair<ValueType>{key, ValueType(value)};
    }
};

template <class T> class AtomicChange {
    T &object;

public:
    AtomicChange(T &object) : object(object) {}

    template <typename... Args> bool operator()(Args &&...kwargs) {
        T copy = object;
        bool ok = true;

        ([&] 
        {
            KeyValuePair kv = kwargs;
            if (!ok) return;
            
            if (!SetKeyValue(copy, kv)) {
                ok = false;
            }
        }(), ...);

        if (ok) {
            object = copy;
        }

        return ok;
    }
};

#endif
