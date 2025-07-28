#pragma once
#ifndef EMVG_MAIN_H_
#define EMVG_MATH_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <string>

#include "3rdparty/stb_image_write.h"

#include "color.h"
#include "utility.h"

inline constexpr double kPi = 3.1415926535897932384626433832795;
inline constexpr double kTau = kPi * 2;
inline constexpr double kOneDeg = (kPi / 180);

inline constexpr double kE = 2.7182818284590452353602874713527;

namespace emvg {
    enum class BlendType {
        kNoBlend,
        kBlendAdd,
        kBlendSub,
        kBlendMul,
    };

    constexpr int kWidth = 512, kHeight = 512;

    extern std::array<unsigned char, kWidth * kHeight * 3> canvas;

    void ClearCanvas();
    void DrawPixel(int x, int y, Color c, BlendType blend = BlendType::kNoBlend);
    void Run(int end_time);
}

#endif