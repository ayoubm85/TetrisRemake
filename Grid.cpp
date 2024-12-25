#include <SFML/Graphics.hpp>
#include "Grid.hpp"

using namespace std;
using namespace sf;

Grid::Grid()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			grid[i][j] = 0;
		}
	}
}

Grid::~Grid() = default;

void Grid::setCell(int x, int y, int color)
{
	grid[x][y] = color;
}

int Grid::get(int x, int y)
{
	return grid[x][y];
}

void Grid::draw(RenderWindow* window)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
			cell.setPosition(Vector2f(j * CELL_SIZE, i * CELL_SIZE));

			switch (grid[i][j])
			{
			case 0:
				cell.setFillColor(Color::Black);
				break;
			case 1:
				cell.setFillColor(Color::Cyan);
				break;
			case 2:
				cell.setFillColor(Color::Yellow);
				break;
			case 3:
				cell.setFillColor(Color::Magenta);
				break;
			case 4:
				cell.setFillColor(Color::Red);
				break;
			case 5:
				cell.setFillColor(Color::Green);
				break;
			case 6:
				cell.setFillColor(Color::Blue);
				break;
			case 7:
				cell.setFillColor(Color::White);
				break;
			}
			cell.setOutlineColor(Color::White);
			cell.setOutlineThickness(1);
			window->draw(cell);
		}
	}
}