#include "shapes.h"

#include <algorithm>

#include "renderer.h"
#include "utils.h"

namespace cr
{
	Rectangle::Rectangle(Rect rect, char fill, bool border) :
		rect(rect), fill(fill), border(border) { }

	void Rectangle::draw()
	{
		rect.scale.x = std::clamp(rect.scale.x, 2, INT_MAX);
		rect.scale.y = std::clamp(rect.scale.y, 2, INT_MAX);

		if (border)
		{
			// Corners
			Renderer::setPixel(Int2(rect.pos.x, rect.pos.y), DRAW_BOX_TL);
			Renderer::setPixel(Int2(rect.pos.x + rect.scale.x - 1, rect.pos.y), DRAW_BOX_TR);
			Renderer::setPixel(Int2(rect.pos.x, rect.pos.y + rect.scale.y - 1), DRAW_BOX_BL);
			Renderer::setPixel(Int2(rect.pos.x + rect.scale.x - 1, rect.pos.y + rect.scale.y - 1), DRAW_BOX_BR);

			// Edges
			if (rect.scale.x > 2)
			{
				Renderer::drawLine(Int2(rect.pos.x + 1, rect.pos.y), Int2(rect.pos.x + rect.scale.x - 2, rect.pos.y), DRAW_BOX_HRZ);
				Renderer::drawLine(Int2(rect.pos.x + 1, rect.pos.y + rect.scale.y - 1), Int2(rect.pos.x + rect.scale.x - 2, rect.pos.y + rect.scale.y - 1), DRAW_BOX_HRZ);
			}

			if (rect.scale.y > 2)
			{
				Renderer::drawLine(Int2(rect.pos.x, rect.pos.y + 1), Int2(rect.pos.x, rect.pos.y + rect.scale.y - 2), DRAW_BOX_VRT);
				Renderer::drawLine(Int2(rect.pos.x + rect.scale.x - 1, rect.pos.y + 1), Int2(rect.pos.x + rect.scale.x - 1, rect.pos.y + rect.scale.y - 2), DRAW_BOX_VRT);
			}

			Renderer::drawBox(Rect(rect.pos.x + 1, rect.pos.y + 1, rect.scale.x - 2, rect.scale.y - 2), fill);
		}
		else
		{
			Renderer::drawBox(Rect(rect.pos.x, rect.pos.y, rect.scale.x, rect.scale.y), fill);
		}
	}

	Circle::Circle(Int2 center, int radius, char fill, int step) :
		center(center), radius(radius), fill(fill), step(step) { }

	void Circle::draw()
	{
		step = std::clamp(step, 1, INT_MAX);

		for (int x = 0; x <= radius * 2; x++)
		{
			for (int y = 0; y <= radius * 2; y++)
			{
				float dx = abs(x - radius);
				float dy = abs(y - radius);
				float dt = sqrt(dx * dx + dy * dy);

				if (dt <= radius)
					for (int i = 0; i < step; i++)
						Renderer::setPixel(Int2(x * step + i + center.x - radius, y + center.y - radius), fill);
			}
		}
	}
}