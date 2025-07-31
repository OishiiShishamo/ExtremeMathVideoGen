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
#include "global.h"

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
    void DrawPixelAA(int x, int y, Color c, double diff, double eps = 0.01, BlendType blend = BlendType::kNoBlend);
    void Run(int end_time);
}

#endif