#include "renderer.h"
#include "shapes.h"

int main()
{
	cr::Renderer::init();

	while (true)
	{
		cr::Renderer::updateResolution();
		cr::Renderer::clearScreen();

		// Examples
		cr::Renderer::writeText(cr::Int2(2, 1), "Hello World!");

		cr::Renderer::setPixel(cr::Int2(2, 2), DRAW_GRADIENT_1);
		cr::Renderer::setPixel(cr::Int2(3, 2), DRAW_GRADIENT_2);
		cr::Renderer::setPixel(cr::Int2(4, 2), DRAW_GRADIENT_3);
		cr::Renderer::setPixel(cr::Int2(5, 2), DRAW_SOLID);

		// Letter H
		cr::Renderer::drawLine(cr::Int2(2, 3), cr::Int2(2, 9), DRAW_BOX_VRT);
		cr::Renderer::drawLine(cr::Int2(3, 6), cr::Int2(6, 6), DRAW_BOX_HRZ);
		cr::Renderer::drawLine(cr::Int2(7, 3), cr::Int2(7, 9), DRAW_BOX_VRT);

		// Letter I
		cr::Renderer::drawLine(cr::Int2(10, 3), cr::Int2(10, 9), DRAW_BOX_VRT);

		cr::Rectangle rbns(cr::Rect(2, 10, 10, 5), DRAW_BLANK);
		rbns.draw();

		cr::Rectangle rbs(cr::Rect(12, 10, 10, 5), DRAW_SOLID);
		rbs.draw();

		cr::Rectangle rnbs(cr::Rect(22, 10, 10, 5), DRAW_SOLID, false);
		rnbs.draw();

		cr::Circle c(cr::Int2(9, 22), 7, DRAW_SOLID);
		c.draw();

		cr::Renderer::display();
	}
}