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
			grid[i][j] = 'E';
		}
	}
}


void Grid::setCell(int x, int y, char tetriminosType)
{
	grid[x][y] = tetriminosType;
}

char Grid::getCell(int x, int y)
{
	return grid[x][y];
}

void Grid::drawGrid(RenderWindow* window)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
			cell.setPosition(Vector2f(j * CELL_SIZE, i * CELL_SIZE));

			switch (grid[i][j])
			{
			case 'E':
				cell.setFillColor(Color::Black);
				break;
			case 'I':
				cell.setFillColor(Color::Cyan);
				break;
			case 'O':
				cell.setFillColor(Color::Yellow);
				break;
			case 'T':
				cell.setFillColor(Color::Magenta);
				break;
			case 'S':
				cell.setFillColor(Color::Red);
				break;
			case 'Z':
				cell.setFillColor(Color::Green);
				break;
			case 'J':
				cell.setFillColor(Color::Blue);
				break;
			case 'L':
				cell.setFillColor(Color::White);
				break;
			}
			cell.setOutlineColor(Color::White);
			cell.setOutlineThickness(1);
			window->draw(cell);
		}
	}
}

void Grid::addTetriminosToGrid(const Tetriminos& tetriminos)
{
	const ShapeTetriminos& shape = tetriminos.getShape();
	const int x = tetriminos.getX();
	const int y = tetriminos.getY();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shape.getShape()[i][j] == 1)
			{
				Grid::setCell(i + x, j + y, shape.getId());
			}
		}
	}
}