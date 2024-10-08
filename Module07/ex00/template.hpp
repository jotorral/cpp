#pragma once
#include <string>
#include <iostream>

template<typename T>
void swap (T &a, T &b)
{
    T   temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min (T const &a, T const &b)
{
    return (a >= b) ? b : a;
}

template<typename T>
T max (T const &a, T const &b)
{
    return (a <= b) ? b : a;
}
