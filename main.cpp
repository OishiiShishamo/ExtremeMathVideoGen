#include "main.h"

#include <algorithm>
#include <execution>
#include <numeric>
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <string>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "3rdparty/stb_image_write.h"

#include "color.h"
#include "utility.h"
#include "global.h"

namespace emvg {
    std::array<unsigned char, kWidth * kHeight * 3> canvas; 
    
    void ClearCanvas() {
        canvas.fill(0);
    }

    void DrawPixel(int x, int y, Color c, BlendType blend) {
        int idx = (y * kWidth + x) * 3;
        switch (blend) {
        case BlendType::kNoBlend:
            canvas[idx] = c.GetRInt();
            canvas[idx + 1] = c.GetGInt();
            canvas[idx + 2] = c.GetBInt();
            break;
        case BlendType::kBlendAdd:
            canvas[idx] = ChMin(canvas[idx] + c.GetR(), 255);
            canvas[idx + 1] = ChMin(canvas[idx + 1] + c.GetG(), 255);
            canvas[idx + 2] = ChMin(canvas[idx + 2] + c.GetB(), 255);
            break;
        case BlendType::kBlendSub:
            canvas[idx] = ChMin(canvas[idx] - c.GetRInt(), 0);
            canvas[idx + 1] = ChMax(canvas[idx + 1] - c.GetGInt(), 0);
            canvas[idx + 2] = ChMax(canvas[idx + 2] - c.GetBInt(), 0);
            break;
        case BlendType::kBlendMul:
            canvas[idx] *= static_cast<double>(c.GetRInt()) / 255.0f;
            canvas[idx + 1] *= static_cast<double>(c.GetGInt()) / 255.0f;
            canvas[idx + 2] *= static_cast<double>(c.GetBInt()) / 255.0f;
            break;
        }
    }

    void DrawPixelAA(int x, int y, Color c, double diff, double eps, BlendType blend) {
        DrawPixel(x, y, c * (1.0f - diff / eps), blend);
    }

    void Run(int end_time) {
        int time = 0;
        std::array<int, kWidth * kHeight> indices;
        std::iota(indices.begin(), indices.end(), 0);
        while (time != end_time) {
            ClearCanvas();
            std::for_each(std::execution::par, indices.begin(), indices.end(), [&](int i) {
                int x = i % kWidth;
                int y = i / kWidth;
                double dx = x - kWidth / 2.0;
                double dy = y - kHeight / 2.0;
                double r = std::sqrt(dx * dx + dy * dy);
                double angle = std::atan2(dy, dx);
                double phase = angle + r * 0.05 + time * 0.05;
                double diff = std::abs(std::sin(phase) * std::exp(-r * 0.02));
                if (diff < 0.5) {
                    DrawPixelAA(x, y, GamingColor(time), diff, 0.5, BlendType::kBlendAdd);
                }
            });
            stbi_write_bmp(("./output/" + std::to_string(time) + ".bmp").c_str(), kWidth, kHeight, 3, canvas.data());
            time++;
			if (time != 0) std::cout << "Progress: " << static_cast<double>(time) / static_cast<double>(end_time) * 100 << "%" << std::endl;
			else std::cout << "Progress: 0%" << std::endl;
        }
    }
}

int main() {
    emvg::MathInit();
    int end_time = 0;
    std::cout << "Please End Time." << std::endl << ">";
    std::cin >> end_time;
    std::cout << "Please Wait..." << std::endl;
    emvg::Run(end_time);
    std::cout << "The Ended." << std::endl;
    return 0;
}