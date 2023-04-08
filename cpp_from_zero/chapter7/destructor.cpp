#include <iostream>
#include <memory>

class BasicArray {
public:
    // Destructor
    // Defined by a compiler implicitly if it doesn't
    // For upcast by a derived class, a destructor of a base class shoule be
    // a virtual function
    virtual ~BasicArray() {
        std::cout << "BasicArray::~BasicArray() is called" << std::endl;
    }

    virtual void Set(int index, int value) = 0;
    virtual int Get(int index) const = 0;
};

class DynamicArray : public BasicArray {
public:
    DynamicArray(int size, int initial_value) {
        data_ = new int[size];
        for (auto i = 0; i < size; ++i) {
            data_[i] = initial_value;
        }
    }

    // Override the destructor of the base class
    ~DynamicArray() override;

    void Set(int index, int value) {
        data_[index] = value;
    }

    int Get(int index) const {
        return data_[index];
    }

private:
    int* data_;
};

// Define a destructor outside the class
DynamicArray::~DynamicArray() {
    std::cout << "DynamicArray::~DynamicArray() is called" << std::endl;
    delete[] data_;
}

class BadResourceManager {
public:
    BadResourceManager() {
        data1_ = new int();
        data2_ = new int(); // If allocation of data2_ failed, data1_ is not released
    }

    ~BadResourceManager() noexcept { // "noexcept": doesn't throw an exception
        delete data1_;
        delete data2_;
    }

    void Set1(int value) {
        *data1_ = value;
    }
    void Set2(int value) {
        *data2_ = value;
    }

    int Get1() {
        return *data1_;
    }
    int Get2() {
        return *data2_;
    }

private:
    int* data1_;
    int* data2_;
};

// RAII (Resource Acquisition Is Initialization):
// Aquire a resource on initialization of an object (by a constructor),
// and release the resource on deletion of the object (by a destructor)
class Resource {
public:
    Resource() {
        // Only one resource can be managed to avoid missing of destructor calling
        data_ = new int();
    }

    ~Resource() {
        std::cout << "Resource::~Resource() is called" << std::endl;
        delete data_;
    }

    void Set(int value) {
        *data_ = value;
    }

    int Get() {
        return *data_;
    }

private:
    int* data_;
};

// Manage RAII resource
class GoodResourceManager {
public:
    void Set1(int value) {
        data1_.Set(value);
    }
    void Set2(int value) {
        data1_.Set(value);
    }

    int Get1() {
        return data1_.Get();
    }
    int Get2() {
        return data2_.Get();
    }

private:
    Resource data1_;
    Resource data2_;
};

int main() {
    DynamicArray d(5, 1);
    std::cout << d.Get(2) << std::endl;
    d.Set(2, 10);
    std::cout << d.Get(2) << std::endl;

    GoodResourceManager grm;
    grm.Set1(10);
    grm.Set2(20);

    std::cout << grm.Get1() << ", " << grm.Get2() << std::endl;

    // Upcast by the base class
    // The destructor of the derived class is called by function overriding
    std::unique_ptr<BasicArray> b(new DynamicArray(5, 1));
    std::cout << b->Get(2) << std::endl;
    b->Set(2, 10);
    std::cout << b->Get(2) << std::endl;

    return 0;
} // Destructors of local instances are called
// A destructor of the derived class is called before that of the base class
