#pragma once
#include "Tetriminos.hpp"
#include "Shape.hpp"
#include <iostream>

using namespace std;

int Tetriminos::instanceCount = 0;

Tetriminos::Tetriminos(const ShapeTetriminos& shape, const int startX, const int startY) : shape(shape), x(startX), y(startY) 
{
	counter();
	id = shape.getId() + to_string(getInstanceCount());
	cout << id << endl;
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

string Tetriminos::getId() const 
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

void Tetriminos::moveLeft() 
{
	this->y--;
}

void Tetriminos::moveRight() 
{
	y++;
}

void Tetriminos::moveDown() 
{
	this->x++;
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
