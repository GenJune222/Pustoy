#ifndef PUSTOY_INTMATRIX_H
#define PUSTOY_INTMATRIX_H
#include "IntArray.h"
#include <cstddef>
#include <iostream>

struct IntMatrix : public IntArray {
    size_t rows;
    size_t cols;

    IntMatrix(size_t r, size_t c);
    ~IntMatrix() = default;
    IntMatrix(const IntMatrix& rhs);
    IntMatrix& operator=(const IntMatrix& rhs);
    IntMatrix(IntMatrix&& rhs);
    IntMatrix& operator=(IntMatrix&& rhs);

    int& at(size_t i, size_t j);
    const int& at(size_t i, size_t j) const;

    void print() const;

    void addRow(size_t afterRow, int value); // команда I
    void addCol(size_t afterCol, int value); // команда II
    void addRowCol(size_t afterRow, size_t afterCol); // команда III
};

#endif
