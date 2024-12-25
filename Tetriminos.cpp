#include "Tetriminos.hpp"
#include "Shape.hpp"

using namespace std;

int Tetriminos::instanceCount = 0;

Tetriminos::Tetriminos(const ShapeTetriminos& shape, const int startX, const int startY, const int id) : shape(shape), x(startX), y(startY), id(id) 
{
	counter();
}

void Tetriminos::counter() 
{
	instanceCount++;
}

int Tetriminos::getInstanceCount() const 
{
	return instanceCount;
}

const ShapeTetriminos& Tetriminos::getShape() const 
{
	return shape;
}

char Tetriminos::getId() const 
{
	return id;
}

int Tetriminos::getX() const 
{
	return x;
}

int Tetriminos::getY() const 
{
	return y;
}

void Tetriminos::setShape(const ShapeTetriminos& shape) 
{
	this->shape = shape;
}

void Tetriminos::setX(int x) 
{
	this->x = x;
}

void Tetriminos::setY(int y) 
{
	this->y = y;
}

void Tetriminos::moveLeft() 
{
	setX(x--);
}

void Tetriminos::moveRight() 
{
	setX(x++);
}

void Tetriminos::moveDown() 
{
	setY(y++);
}

void Tetriminos::rotateClockwise()
{
	int n = shape.getShape().size();
	vector<vector<int>> currentShape = shape.getShape();
	vector<vector<int>> newShape(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newShape[j][n - i - 1] = currentShape[i][j];
		}
	}

	setShape(ShapeTetriminos(newShape, shape.getColor(), shape.getId()));
}

void Tetriminos::rotateCounterClockwise() 
{
	int n = shape.getShape().size();
	vector<vector<int>> currentShape = shape.getShape();
	vector<vector<int>> newShape(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newShape[n - j - 1][i] = currentShape[i][j];
		}
	}

	setShape(ShapeTetriminos(newShape, shape.getColor(), shape.getId()));
}
