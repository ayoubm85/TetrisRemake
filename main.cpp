#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>   
#include <iostream>
#include "Grid.hpp"



using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode({ 300, 600 }), "Tetris Grid");
	ShapeTetriminos shape(I, COLORS[1], 'I');
	Tetriminos tetriminos(shape, 0, 0, 1);
	Grid grid;

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent()) {
			if (event->is<Event::Closed>())
			{
				window.close();
			}
		}
		window.clear();
		grid.addTetriminosToGrid(tetriminos);
		grid.drawGrid(&window);
		window.display();

		

		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 4; j++)
		//	{
		//		cout << tetriminos.getShape().getShape()[i][j] << " ";
		//	}

		//	cout << endl;
		//}
		//
		//tetriminos.rotateClockwise();

		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 4; j++)
		//	{
		//		cout << tetriminos.getShape().getShape()[i][j] << " ";
		//	}

		//	cout << endl;
		//}

		//tetriminos.rotateCounterClockwise();

		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 4; j++)
		//	{
		//		cout << tetriminos.getShape().getShape()[i][j] << " ";
		//	}

		//	cout << endl;
		//}

	}

    return 0;
}