#pragma once

#define DRAW_BOX_TL char(218)
#define DRAW_BOX_TR char(191)
#define DRAW_BOX_BL char(192)
#define DRAW_BOX_BR char(217)
#define DRAW_BOX_VRT char(179)
#define DRAW_BOX_HRZ char(196)

#define DRAW_BOX_SL char(195)
#define DRAW_BOX_SR char(180)
#define DRAW_BOX_ST char(194)
#define DRAW_BOX_SB char(193)

#define DRAW_BLANK char(255)
#define DRAW_GRADIENT_1 char(176)
#define DRAW_GRADIENT_2 char(177)
#define DRAW_GRADIENT_3 char(178)
#define DRAW_SOLID char(219)

namespace cr
{
	struct Int2
	{
		int x;
		int y;

		Int2(int x = 0, int y = 0) : x(x), y(y) { }

		Int2 operator+(Int2 const& obj) { return Int2(x + obj.x, y + obj.y); }

		bool operator==(Int2 const& obj) { return x == obj.x && y == obj.y; }
		bool operator!=(Int2 const& obj) { return x != obj.x || y != obj.y; }
	};

	struct Rect
	{
		Int2 pos;
		Int2 scale;

		Rect(Int2 pos, Int2 scale) : pos(pos), scale(scale) { }
		Rect(int x, int y, int width, int height) : pos(Int2(x, y)), scale(Int2(width, height)) { }
	};
}