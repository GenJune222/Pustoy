#include "IntArray.h"
#include <cstddef>

IntArray::IntArray(int i) : k(1), a(new int[1]) {
    a[0] = i;
}

IntArray::~IntArray() {
    delete[] a;
}

IntArray::IntArray(const IntArray& rhs) : a(new int[rhs.getsize()]), k(rhs.getsize()) {
    for (size_t i = 0; i < rhs.getsize(); ++i)
        a[i] = rhs.get(i);
}

IntArray& IntArray::operator=(const IntArray& rhs) {
    int* p = new int[rhs.getsize()];
    for (size_t i = 0; i < rhs.getsize(); ++i)
        p[i] = rhs.get(i);
    delete[] a;
    a = p;
    k = rhs.getsize();
    return *this;
}

IntArray::IntArray(IntArray&& rhs) : a(rhs.a), k(rhs.getsize()) {
    rhs.a = nullptr;
}

IntArray& IntArray::operator=(IntArray&& rhs) {
    delete[] a;
    a = rhs.a;
    k = rhs.getsize();
    rhs.a = nullptr;
    return *this;
}

int IntArray::add(int i) {
    int* tmp = new int[getsize() + 1];
    for (size_t j = 0; j < getsize(); ++j)
        tmp[j] = get(j);
    tmp[getsize()] = i;
    delete[] a;
    a = tmp;
    ++k;
    return i;
}

int IntArray::get(size_t id) const noexcept {
    return a[id];
}

size_t IntArray::getsize() const noexcept {
    return k;
}

int IntArray::last() const noexcept {
    return get(getsize() - 1);
}
