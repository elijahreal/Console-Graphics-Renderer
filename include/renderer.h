#pragma once

#include <string>

#include "utils.h"

namespace cr
{
	class Renderer
	{
	private:
		inline static std::string framebuffer = "";
		inline static Int2 prevScale = { 0, 0 };
		inline static Int2 scale = { 0, 0 };

	public:
		static void init();
		static void toggleCursor(bool visible);
		static void clearScreen();
		static void updateResolution();

		static void setPixel(Int2 pos, char c);
		static void drawLine(Int2 start, Int2 end, char c);
		static void drawBox(Rect rect, char fill);
		static void writeText(Int2 pos, std::string s, bool alignLeft = true);

		static void display();

		static Int2 getScale() { return scale; }
	};
}