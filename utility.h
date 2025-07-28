#pragma once
#ifndef EMVG_UTILITY_H_
#define EMVG_UTILITY_H_

#include <algorithm>

namespace emvg {
    int ChMax(const int& a, const int& b) {
        return std::max(a, b);
    }

    int ChMin(const int& a, const int& b) {
        return std::min(a, b);
    }
}

#endif