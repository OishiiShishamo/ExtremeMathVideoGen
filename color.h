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

namespace emvg {
	class Color {
	public:
		Color() = default;
		Color(int r, int g, int b) : r_(r), g_(g), b_(b) {
			if (r_ > 255) r_ = 255;
			if (g_ > 255) g_ = 255;
			if (b_ > 255) b_ = 255;
			if (r_ < 0) r_ = 0;
			if (g_ < 0) g_ = 0;
			if (b_ < 0) b_ = 0;
		}

		int GetR() const { return r_; }
		int GetG() const { return g_; }
		int GetB() const { return b_; }

		Color operator+(const Color& rhs) const { return Color(GetR() + rhs.GetR(), GetG() + rhs.GetG(), GetB() + rhs.GetB()); }
		Color operator+(double scalar) const { return Color(GetR() + scalar, GetG() + scalar, GetB() + scalar); }
		Color operator-(const Color& rhs) const { return Color(GetR() - rhs.GetR(), GetG() - rhs.GetG(), GetB() - rhs.GetB()); }
		Color operator-(double scalar) const { return Color(GetR() - scalar, GetG() - scalar, GetB() - scalar); }
		Color operator*(const Color& rhs) const { return Color(GetR() * rhs.GetR(), GetG() * rhs.GetG(), GetB() * rhs.GetB()); }
		Color operator*(double scalar) const { return Color(GetR() * scalar, GetG() * scalar, GetB() * scalar); }
		Color operator/(const Color& rhs) const { return Color(GetR() / rhs.GetR(), GetG() / rhs.GetG(), GetB() / rhs.GetB()); }
		Color operator/(double scalar) const { return Color(GetR() / scalar, GetG() / scalar, GetB() / scalar); }
	private:
		int r_ = 0;
		int g_ = 0;
		int b_ = 0;
	};
}

#endif