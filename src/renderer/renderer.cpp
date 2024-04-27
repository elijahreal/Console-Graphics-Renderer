#include "renderer.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <windows.h>

namespace cr
{
	void Renderer::init()
	{
		toggleCursor(false);
		updateResolution();
		clearScreen();
	}

	void Renderer::toggleCursor(bool visible)
	{
		CONSOLE_CURSOR_INFO curInfo;
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
		curInfo.bVisible = visible;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	}

	void Renderer::clearScreen()
	{
		framebuffer = "";
		framebuffer.append(scale.x * scale.y, ' ');
	}

	void Renderer::updateResolution()
	{
		CONSOLE_SCREEN_BUFFER_INFO info;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		scale.x = info.srWindow.Right - info.srWindow.Left + 1;
		scale.y = info.srWindow.Bottom - info.srWindow.Top + 1;

		if (scale != prevScale)
		{
			system("cls");
			system("cls");
		}

		prevScale = scale;
	}

	void Renderer::setPixel(Int2 pos, char c)
	{
		if (pos.x >= 0 && pos.x < scale.x && pos.y >= 0 && pos.y < scale.y)
		{
			framebuffer[pos.y * scale.x + pos.x] = c;
		}
	}

	// Got this from GeeksForGeeks
	void Renderer::drawLine(Int2 start, Int2 end, char c)
	{
		if (start == end)
			return;

		int dx = end.x - start.x;
		int dy = end.y - start.y;

		int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

		float xInc = dx / (float)steps;
		float yInc = dy / (float)steps;

		float x = start.x;
		float y = start.y;
		for (int i = 0; i <= steps; i++)
		{
			setPixel({ (int)round(x), (int)round(y) }, c);
			x += xInc;
			y += yInc;
		}
	}

	void Renderer::drawBox(Rect rect, char fill)
	{
		for (int x = 0; x < rect.scale.x; x++)
		{
			for (int y = 0; y < rect.scale.y; y++)
			{
				Renderer::setPixel(Int2(x + rect.pos.x, y + rect.pos.y), fill);
			}
		}
	}

	void Renderer::writeText(Int2 pos, std::string s, bool alignLeft)
	{
		if (alignLeft)
			for (int i = 0; i < s.length(); i++)
				setPixel(Int2(pos.x + i, pos.y), s[i]);
		else
			for (int i = 0; i < s.length(); i++)
				setPixel(Int2(pos.x - i, pos.y), s[s.length() - i - 1]);
	}

	void Renderer::display()
	{
		std::cout.flush();
		COORD coord = { 0, 0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		for (char c : framebuffer)
		{
			std::cout << c;
		}
	}
}