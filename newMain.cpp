#include <iostream>
#include <fstream>
#include "IntMatrix.h"

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;

    std::ifstream fin(argv[1]);
    if (!fin) return 1;

    size_t r, c;
    fin >> r >> c;
    if (!fin) return 1;

    try {
        IntMatrix m(r, c);
        for (size_t i = 0; i < r; ++i)
            for (size_t j = 0; j < c; ++j) {
                fin >> m.at(i, j);
                if (!fin) return 1;
            }

        int cmd, p1, p2;
        while (std::cin >> cmd >> p1 >> p2) {
            try {
                if (cmd == 1) {
                    if (p1 > m.rows) return 3;
                    m.addRow(p1 == 0 ? 0 : p1, p2);
                } else if (cmd == 2) {
                    if (p1 > m.cols) return 3;
                    m.addCol(p1 == 0 ? 0 : p1, p2);
                } else if (cmd == 3) {
                    if (p1 > m.rows || p2 > m.cols) return 3;
                    m.addRowCol(p1 == 0 ? 0 : p1, p2 == 0 ? 0 : p2);
                } else {
                    return 3;
                }
            } catch (std::bad_alloc&) {
                return 2;
            }
            m.print();
        }

        if (!std::cin.eof()) return 1;

    } catch (std::bad_alloc&) {
        return 2;
    }

    return 0;
}
