#ifndef DIJKSTRAANALYSER_DYNAMICARRAY_H
#define DIJKSTRAANALYSER_DYNAMICARRAY_H

template <typename T>
class DynamicArray {
    T* t = nullptr;
    int length = 1;//długość wektora
    int amountOfElements = 0;//ilość elementów wektora

    void copy(T* to) const;
    void increaseLength();
public:
    DynamicArray();
    DynamicArray(const DynamicArray<T> &copy);
    void push(T elem);
    T& operator[](int idx);
    T pop();
    int size() const;
    void resize(int size);
    T* begin() const;
    T* end() const;
    void clear();
    DynamicArray<T> clone() const;
    ~DynamicArray();
};

#include "DynamicArray_impl.h"
#endif //DIJKSTRAANALYSER_DYNAMICARRAY_H
