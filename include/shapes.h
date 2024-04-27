#pragma once

#include "utils.h"

namespace cr
{
	struct Rectangle
	{
		Rect rect;

		char fill;
		bool border;

		Rectangle(Rect rect = Rect(0, 0, 2, 2), char fill = ' ', bool border = true);

		void draw();
	};

	struct Circle
	{
		Int2 center;
		int radius;

		char fill;
		int step;

		Circle(Int2 center = { 0, 0 }, int radius = 2, char fill = 'X', int step = 2);

		void draw();
	};
}