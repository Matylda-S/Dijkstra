#ifndef DIJKSTRAANALYSER_HEAP_H
#define DIJKSTRAANALYSER_HEAP_H

#include "DynamicArray.h"
#include "Helpers.h"
#include <iostream>

template<typename T>
class Heap /// min heap
{
private:
    DynamicArray<T> t;

    bool (*comp)(const T &, const T &);

    void goUp(int v);

    void goDown(int v);

public:
    Heap(bool (*comp)(const T &, const T &));

    void build(DynamicArray<T> arr);

    void push(T val);

    T top() const;

    int size() const;

    bool empty() const;

    T pop();

    void printTree();
};

#include "Heap_impl.h"

#endif //DIJKSTRAANALYSER_HEAP_H
