#include <iostream>
#include <map>
#include <string>
#include <vector>

// union
// Share the same memory with several data types
// therefore memory size can be reduced than individual allocation
union X {
    int m1;
    double m2;
    std::string m3;

    X() : m1(0) {}
    ~X() {}
};

// Destructor call
// from c++17, std::destroy_at in <memory>
template <class T>
void destroy_at(T* location) {
    location->~T();
}

// Example: JSON object
struct Value {
    // Kind of data type
    enum class Kind {
        Null,
        Object,
        Array,
        String,
        Number,
        Boolean
    };
    Kind k_;

    // Data object
    union Data {
        bool b_;
        double num_;
        std::string str_;
        std::vector<Value> arr_;
        std::map<std::string, Value> obj_;

        Data() : b_() {}
        ~Data() {}
    } data_;

    Value() : k_() {}

    Value(std::string s) : k_(Kind::String) {
        new(&data_.str_) std::string(std::move(s));
    }

    ~Value() {
        // Call an appropriate destructor by its kind
        switch (k_) {
            case Kind::Object:
                destroy_at(&data_.obj_);
                break;
            case Kind::Array:
                destroy_at(&data_.arr_);
                break;
            case Kind::String:
                destroy_at(&data_.str_);
                break;
            default:
                break;
        }
    }

    Kind GetKind() {
        return k_;
    }

    std::string GetStringOr(std::string default_value) {
        return (k_ == Kind::String) ? data_.str_ : default_value;
    }
};

union A {
    int x;
    int y[4];
};

struct B {
    A a;
};

union C {
    B b;
    int k;
};

struct XX {
    const int a;
    int b;
};

union Y {
    XX x;
    int k;
};

union Z {
    int int_value;
    char char_value[4];
};

int f() {
    // Only one data member in the union can be active and its lifetime starts

    C c; // Lifetime of data members in C doesn't start
    c.b.a.y[3] = 4; // OK: lifetime of c.b and c.b.a.y start

    return c.b.a.y[3]; // OK: c.b.a.y indicates the crated object
}

int g() {
    Y y = {{1, 2}}; // OK: y.x is an active data member

    int n = y.x.a;
    y.k = 4;       // OK: lifetime of y.x finishes
                   //     lifetime of y.k starts and be active
    y.x.b = n;     // Undefined behavior: a default constructor of XX is deleted
                   // therefore lifetime of y.x doesn't start implicitly

    return n;
}

int main() {
    X x;

    // Placement new: place instance to a specific memory address
    // Need to call a constructor of std::string explicitly
    new (&x.m3) std::string("aaa");

    std::cout << x.m3 << std::endl;

    // Need to call a destructor of std::string explicitly
    destroy_at(&x.m3);

    // Refer appropriate data member according to the kind of data
    Value v1;
    std::cout << static_cast<int>(v1.GetKind()) << ": " << v1.GetStringOr("bbb") << std::endl;
    Value v2("aaa");
    std::cout << static_cast<int>(v2.GetKind()) << ": " << v2.GetStringOr("bbb") << std::endl;

    f();
    g(); // Undefined behavior by reference of inactive data member in the union

    Z z; // Lifetime of data members in Z doesn't start
    z.int_value = 65535; // OK: lifetime of z.int_value starts and the object is created
    z.char_value[0];     // NG: lifetime of z.char_value doesn't start

    return 0;
}
