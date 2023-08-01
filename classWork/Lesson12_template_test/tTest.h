#ifndef TTEST_H
#define TTEST_H

#include <iostream>

template <typename T>
void print(const T &val)
{
    std::cout << typeid(val).name() << ": " << val << std::endl;
}

#endif // TTEST_H
