#include <iostream>

class Integer {
public:
    explicit Integer(int value) : value_(value) {}

    int Value() const {
        return value_;
    }

    // Unary opeartor "-" overloading as a member function
    // It's a better way
    Integer operator-() const {
        Integer tmp(-Value()); // Using this object
        return tmp;
    }

    // Binary operator "+" overloading as a member function
    // It is called as a member function of an instance
    // which is left-hand side operand of this operator
    //
    // Integer a, b;
    // Integer c = a + b; // a.operator+(b)
    //
    // Integer operator+(const Integer& rhs) const {
    //     Integer tmp(Value() + rhs.Value());
    //     return tmp;
    // }

    // Pre-increment
    Integer& operator++() {
        ++value_;
        return *this;
    }

    // Post-increment
    // int is passed as an argument
    Integer operator++(int) {
        Integer tmp(Value());
        ++value_;
        return tmp;
    }

private:
    int value_;
};

// Unary opeartor "-" overloading as a non-member function
// Integer operator-(Integer& v) {
//     Integer tmp(v.Value());
//     return tmp;
// }

// Binary operator "+" overloading
// It is called as a non-member function
//
// Integer a, b;
// Integer c = a + b; // operator+(a, b)
//
// It is a better way because multiple defintions are required
// by combinations of left / right-hand side operands
Integer operator+(const Integer& lhs, const Integer& rhs) {
    // lhs: left-hand side, rhs: right-hand side
    Integer tmp(lhs.Value() + rhs.Value());
    return tmp;
}

class RealNumber {
public:
    explicit RealNumber(double value) : value_(value) {}

    double Value() const {
        return value_;
    }

private:
    double value_;
};

// Operator overloading of "+" between Integer and RealNumber class
RealNumber operator+(const Integer& lhs, const RealNumber& rhs) {
    RealNumber tmp(lhs.Value() + rhs.Value());
    return tmp;
}
RealNumber operator+(const RealNumber& lhs, const Integer& rhs) {
    RealNumber tmp(lhs.Value() + rhs.Value());
    return tmp;
}

int main() {
    // Overloaded operators should behave the same as the embedded operators
    Integer a(2);
    Integer b = -a;
    Integer c = a + b;

    RealNumber d(3.14);
    RealNumber e = d + a;

    Integer f(1);
    Integer g = ++f;
    Integer h = f++;

    std::cout << a.Value() << std::endl;
    std::cout << b.Value() << std::endl;
    std::cout << c.Value() << std::endl;
    std::cout << e.Value() << std::endl;
    std::cout << f.Value() << std::endl;
    std::cout << g.Value() << std::endl;
    std::cout << h.Value() << std::endl;

    return 0;
}
