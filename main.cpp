#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>   
#include <iostream>
#include "Grid.hpp"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode({ 300, 600 }), "Tetris Grid");
	ShapeTetriminos shape1(S, COLORS[1], 'S');
	ShapeTetriminos shape2(I, COLORS[2], 'I');
	Tetriminos tetriminos(shape1, 2, 1);
	Tetriminos tetriminos2(shape2, 5, 4);
	Grid grid;

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent()) 
		{
			if (event->is<Event::Closed>())
			{
				window.close();
			}
			if (event->is<Event::KeyPressed>()) {
				if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Left) 
				{
					if (grid.isValidMove(tetriminos, 0, -1)) 
						tetriminos.moveLeft();
				}
				else if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Right) 
				{
					if (grid.isValidMove(tetriminos, 0, 1)) 
						tetriminos.moveRight();
				}
				else if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Down) 
				{
					if (grid.isValidMove(tetriminos, 1, 0))
						tetriminos.moveDown();
				}
				grid.updateGrid(tetriminos, &window);
			}
		}
		window.clear();
		grid.addTetriminosToGrid(tetriminos2);
		grid.addTetriminosToGrid(tetriminos);
		grid.drawGrid(&window);
		window.display();
	}
    return 0;
}