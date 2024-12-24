#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>   
#include "Grid.hpp"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode({ 300, 600 }), "Tetris Grid");

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent()) {
			if (event->is<Event::Closed>())
			{
				window.close();
			}
		}
		window.clear();
		Grid grid;
		grid.draw(&window);
		window.display();

	}

    return 0;
}