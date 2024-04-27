#include "renderer.h"
#include "shapes.h"

int main()
{
	cr::Renderer::init();

	while (true)
	{
		cr::Renderer::updateResolution();
		cr::Renderer::clearScreen();

		cr::Rectangle rectangle(cr::Rect(2, 2, 20, 5), ' ', true);
		rectangle.draw();

		cr::Circle circle(cr::Int2(20, 10), 10, 'H', 2);
		circle.draw();

		cr::Renderer::writeText(cr::Int2(cr::Renderer::getScale().x - 2, cr::Renderer::getScale().y - 2), "Made by elijah", false);

		cr::Renderer::display();
	}
}