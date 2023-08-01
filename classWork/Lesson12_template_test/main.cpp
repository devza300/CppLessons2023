#include <iostream>

#include "tTest.h"
#include "IntOnly.h"
#include "FloatOnly.h"
#include "DoubleOnly.h"

template <typename T>
class Super
{
public:
    Super(const T &val) : mm_data(val) {};

    virtual void show() = 0;

protected:
    T mm_data;
};

class A : public Super<int>
{
public:
    A(int val) : Super<int>(val) {};

    virtual void show() override
    {
        std::cout << "A: ";
        print(this->mm_data);
    };
};

class B : public Super<float>
{
public:
    B(float val) : Super<float>(val) {};

    virtual void show() override final
    {
        std::cout << "B: ";
        print(this->mm_data);
    };
};

template <typename V>
class C : public Super<int>
{
public:
    C(const V &val) : Super<int>(*val) {};

    virtual void show() override final
    {
        std::cout << "C: ";
        print(this->mm_data);
    };
};


int main()
{
    print<int>(1);
    print(2.2f);
    print(3.3);
    print("Hello World!");

    /// @bug TEST PTR
    auto ptr_char = &print<char>;
    ptr_char(8);
//    std::cout << (int*) &ptr_char << std::cout;
//    void (*p)(float) = &print<int>;

    intOnly();
    floatOnly();
    doubleOnly();

    A a(123);
    a.show();

    B b(456.0f);
    b.show();

    // same main.cpp : line 67
    C c("");
    c.show();

    return 0;
}
