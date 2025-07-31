#pragma once
#ifndef ZENITHSTG_SRC_COLOR_H_
#define ZENITHSTG_SRC_COLOR_H_

//SIMPLE

#define kColorRed 255, 0, 0
#define kColorGreen 0, 255, 0
#define kColorBlue 0, 0, 255
#define kColorYellow 255, 255, 0
#define kColorAqua 0, 255, 255
#define kColorCyan 0, 255, 255
#define kColorPurple 255, 0, 255
#define kColorOrange 255, 127, 0
#define kColorWhite 255, 255, 255
#define kColorGray 127, 127, 127
#define kColorBlack 0, 0, 0

//NOT-SIMPLE

#define kColorAliceBlue 240, 248, 255
#define kColorAntiqueWhite 250, 235, 215
#define kColorAquamarine 127, 255, 212
#define kColorAzure 240, 255, 255
#define kColorBeige 245, 245, 220
#define kColorBisque 255, 228, 196
#define kColorBlanchedalmond 255, 235, 205
#define kColorBlueViolet 138, 43, 226
#define kColorBrown 165, 42, 42
#define kColorBurlyWood 222, 184, 135

#include <algorithm>

#include "global.h"

namespace emvg {
	class Color {
	public:
		double GetR() const { return r_; }
		double GetG() const { return g_; }
		double GetB() const { return b_; }
		int GetRInt() const { return r_; }
		int GetGInt() const { return g_; }
		int GetBInt() const { return b_; }
		void SetR(double r) { r_ = r; }
		void SetG(double g) { g_ = g; }
		void SetB(double b) { b_ = b; }
		void Saturate() {
			SetR(std::clamp(GetR(), static_cast<double>(0.0f), static_cast<double>(1.0f)));
			SetG(std::clamp(GetG(), static_cast<double>(0.0f), static_cast<double>(1.0f)));
			SetB(std::clamp(GetB(), static_cast<double>(0.0f), static_cast<double>(1.0f)));
		}
		void Saturate255() {
			SetR(std::clamp(GetR(), static_cast<double>(0.0f), static_cast<double>(255.0f)));
			SetG(std::clamp(GetG(), static_cast<double>(0.0f), static_cast<double>(255.0f)));
			SetB(std::clamp(GetB(), static_cast<double>(0.0f), static_cast<double>(255.0f)));
		}
		Color() = default;
		Color(double r, double g, double b) {
			r_ = r;
			g_ = g;
			b_ = b;
		}

		Color operator+(const Color& rhs) const { return Color(GetR() + rhs.GetR(), GetG() + rhs.GetG(), GetB() + rhs.GetB()); }
		Color operator+(double scalar) const { return Color(GetR() + scalar, GetG() + scalar, GetB() + scalar); }
		Color operator-(const Color& rhs) const { return Color(GetR() - rhs.GetR(), GetG() - rhs.GetG(), GetB() - rhs.GetB()); }
		Color operator-(double scalar) const { return Color(GetR() - scalar, GetG() - scalar, GetB() - scalar); }
		Color operator*(const Color& rhs) const { return Color(GetR() * rhs.GetR(), GetG() * rhs.GetG(), GetB() * rhs.GetB()); }
		Color operator*(double scalar) const { return Color(GetR() * scalar, GetG() * scalar, GetB() * scalar); }
		Color operator/(const Color& rhs) const { return Color(GetR() / rhs.GetR(), GetG() / rhs.GetG(), GetB() / rhs.GetB()); }
		Color operator/(double scalar) const { return Color(GetR() / scalar, GetG() / scalar, GetB() / scalar); }
	private:
		double r_ = 0;
		double g_ = 0;
		double b_ = 0;
	};

	Color HsvToRgb(double h, double s = 1.0f, double v = 1.0f) {
		Color result;
		h = std::fmod(h, 360.0f);
		h /= 360.0f;
		result.SetR(std::abs(h * 6 - 3) - 1);
		result.SetG(2 - std::abs(h * 6 - 2));
		result.SetB(2 - std::abs(h * 6 - 4));
		result.Saturate();
		return (((result - 1) * s + 1) * v) * 255.0f;
	}

	Color GamingColor(int time, int offset = 0, double mul = 1) {
		return HsvToRgb(std::fmod((time + offset) * mul, 360.0f), 1, 1);
	}
}

#endif