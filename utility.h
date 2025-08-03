#pragma once
#ifndef EMVG_UTILITY_H_
#define EMVG_UTILITY_H_

#include <algorithm>

#include "global.h"

namespace emvg {
    int ChMax(int& a, const int& b) {
        a = std::max(a, b);
    }

    int ChMin(int& a, const int& b) {
        a = std::min(a, b);
    }

    double Rad(double angle) {
        return (kPi / 180) * angle;
    }

    std::array<double, 360> sin_table;
    std::array<double, 360> cos_table;

    void MathInit() {
        sin_table.fill(10.0);
        cos_table.fill(10.0);
    }

    double FastSin(int x) {
        if (sin_table[x % 360] == 10.0) {
            sin_table[x % 360] = std::sin(Rad(x));
        }
        return sin_table[x % 360];
    }

    double FastCos(int x) {
        if (cos_table[x % 360] == 10.0) {
            cos_table[x % 360] = std::cos(Rad(x));
        }
        return cos_table[x % 360];
    }
}

#endif