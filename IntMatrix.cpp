#include "IntMatrix.h"
#include <stdexcept>

IntMatrix::IntMatrix(size_t r, size_t c) : IntArray(r * c), rows(r), cols(c) {
    for (size_t i = 0; i < r * c; ++i)
        a[i] = 0;
}

IntMatrix::IntMatrix(const IntMatrix& rhs) : IntArray(rhs), rows(rhs.rows), cols(rhs.cols) {}

IntMatrix& IntMatrix::operator=(const IntMatrix& rhs) {
    IntArray::operator=(rhs);
    rows = rhs.rows;
    cols = rhs.cols;
    return *this;
}

IntMatrix::IntMatrix(IntMatrix&& rhs) : IntArray(std::move(rhs)), rows(rhs.rows), cols(rhs.cols) {
    rhs.rows = 0;
    rhs.cols = 0;
}

IntMatrix& IntMatrix::operator=(IntMatrix&& rhs) {
    IntArray::operator=(std::move(rhs));
    rows = rhs.rows;
    cols = rhs.cols;
    rhs.rows = 0;
    rhs.cols = 0;
    return *this;
}

int& IntMatrix::at(size_t i, size_t j) {
    return a[i * cols + j];
}

const int& IntMatrix::at(size_t i, size_t j) const {
    return a[i * cols + j];
}

void IntMatrix::print() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            std::cout << a[i * cols + j] << " ";
        std::cout << "\n";
    }
}

void IntMatrix::addRow(size_t afterRow, int value) {
    IntArray tmp((rows + 1) * cols);
    size_t oldI = 0;
    for (size_t i = 0; i < rows + 1; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i == afterRow)
                tmp.a[i * cols + j] = value;
            else
                tmp.a[i * cols + j] = a[oldI * cols + j];
        }
        if (i != afterRow) oldI++;
    }
    delete[] a;
    a = tmp.a;
    tmp.a = nullptr;
    rows++;
}

void IntMatrix::addCol(size_t afterCol, int value) {
    IntArray tmp(rows * (cols + 1));
    for (size_t i = 0; i < rows; i++) {
        size_t oldJ = 0;
        for (size_t j = 0; j < cols + 1; j++) {
            if (j == afterCol)
                tmp.a[i * (cols + 1) + j] = value;
            else
                tmp.a[i * (cols + 1) + j] = a[i * cols + oldJ++];
        }
    }
    delete[] a;
    a = tmp.a;
    tmp.a = nullptr;
    cols++;
}

void IntMatrix::addRowCol(size_t afterRow, size_t afterCol) {
    addRow(afterRow, 0);
    addCol(afterCol, 0);
}
