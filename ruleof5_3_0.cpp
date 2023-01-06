#include <iostream>
#include <cstddef>
#include <cstring>

/*

from https://en.cppreference.com/w/cpp/language/rule_of_three

If a class requires a user-defined destructor, a user-defined copy constructor,
or a user-defined copy assignment operator, it almost certainly requires all three.

Because the presence of a user-defined (or = default or = delete declared) destructor, copy-constructor,
or copy-assignment operator prevents implicit definition of the move constructor and the move assignment operator,
any class for which move semantics are desirable, has to declare all five special member functions:

Classes that have custom destructors, copy/move constructors or copy/move assignment operators should deal
exclusively with ownership (which follows from the Single Responsibility Principle).
Other classes should not have custom destructors, copy/move constructors or copy/move assignment operators

*/

template <class T, class U = T>
T exchange(T &obj, U &&new_value)
{
    T old_value = std::move(obj);
    obj = std::forward<U>(new_value);
    return old_value;
}

class rule_of_three
{
    char *cstring;                              // raw pointer used as a handle to a dynamically-allocated memory block
    rule_of_three(const char *s, std::size_t n) // to avoid counting twice
        : cstring(new char[n])                  // allocate
    {
        std::memcpy(cstring, s, n); // populate
    }

public:
    rule_of_three(const char *s = "")
        : rule_of_three(s, std::strlen(s) + 1) {}
    ~rule_of_three() // I. destructor
    {
        delete[] cstring; // deallocate
    }
    rule_of_three(const rule_of_three &other) // II. copy constructor
        : rule_of_three(other.cstring)
    {
    }
    rule_of_three &operator=(const rule_of_three &other) // III. copy assignment
    {
        if (this == &other)
            return *this;
        std::size_t n{std::strlen(other.cstring) + 1};
        char *new_cstring = new char[n];            // allocate
        std::memcpy(new_cstring, other.cstring, n); // populate
        delete[] cstring;                           // deallocate
        cstring = new_cstring;
        return *this;
    }
    operator const char *() const // accessor
    {
        return cstring;
    }
};

class rule_of_five
{
    char *cstring; // raw pointer used as a handle to a dynamically-allocated memory block
public:
    rule_of_five(const char *s = "") : cstring(nullptr)
    {
        if (s)
        {
            std::size_t n = std::strlen(s) + 1;
            cstring = new char[n];      // allocate
            std::memcpy(cstring, s, n); // populate
        }
    }
    ~rule_of_five()
    {
        delete[] cstring; // deallocate
    }
    rule_of_five(const rule_of_five &other) // copy constructor
        : rule_of_five(other.cstring)
    {
    }
    rule_of_five(rule_of_five &&other) noexcept // move constructor
        : cstring(exchange(other.cstring, nullptr))
    {
    }
    rule_of_five &operator=(const rule_of_five &other) // copy assignment
    {
        return *this = rule_of_five(other);
    }
    rule_of_five &operator=(rule_of_five &&other) noexcept // move assignment
    {
        std::swap(cstring, other.cstring);
        return *this;
    }
    // alternatively, replace both assignment operators with
    //  rule_of_five& operator=(rule_of_five other) noexcept
    //  {
    //      std::swap(cstring, other.cstring);
    //      return *this;
    //  }
};

class rule_of_zero
{
    std::string cppstring;

public:
    rule_of_zero(const std::string &arg) : cppstring(arg) {}
};

// When a base class is intended for polymorphic use, its destructor may have to be declared public and virtual.
// This blocks implicit moves (and deprecates implicit copies), and so the special member functions have to be declared as defaulted[2].

class base_of_five_defaults
{
public:
    base_of_five_defaults(const base_of_five_defaults &) = default;
    base_of_five_defaults(base_of_five_defaults &&) = default;
    base_of_five_defaults &operator=(const base_of_five_defaults &) = default;
    base_of_five_defaults &operator=(base_of_five_defaults &&) = default;
    virtual ~base_of_five_defaults() = default;
};

int main()
{
    rule_of_three o1{"abc"};
    std::cout << o1 << ' ';
    auto o2{o1}; // I. uses copy constructor
    std::cout << o2 << ' ';
    rule_of_three o3("def");
    std::cout << o3 << ' ';
    o3 = o2; // III. uses copy assignment
    std::cout << o3 << ' ';
} // <- II. all destructors are called 'here'