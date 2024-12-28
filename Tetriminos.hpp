#pragma
#include "Constants.hpp"
#include "Shape.hpp"

class Tetriminos {
public:
	Tetriminos();
	Tetriminos(const ShapeTetriminos& shape, const int startX, const int startY);
	~Tetriminos() = default;

	void counter();
	int getInstanceCount() const;

	const ShapeTetriminos& getShape() const;
	string getId() const;

	int getX() const;
	int getY() const;

	void setShape(const ShapeTetriminos& shape);

	void moveLeft();
	void moveRight();
	void moveDown();

	void rotateClockwise();
	void rotateCounterClockwise();


private:
	static int instanceCount;

	ShapeTetriminos shape;
	string id;
	int x, y;
};