#ifndef SUM_HPP
#define SUM_HPP

template <typename T>
inline T Sum(T a, T b) {
    return a + b;
}

// Extern template:
// avoid implicit instantiation
extern template int Sum<int>(int, int);

#endif // SUM_HPP
