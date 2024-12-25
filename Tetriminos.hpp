#include "Constants.hpp"
#include "Shape.hpp"

class Tetriminos {
public:
	Tetriminos(const ShapeTetriminos& shape, const int startX, const int startY, const int id);
	~Tetriminos() = default;

	void counter();
	int getInstanceCount() const;

	const ShapeTetriminos& getShape() const;
	char getId() const;

	int getX() const;
	int getY() const;


	void setShape(const ShapeTetriminos& shape);
	void setX(int x);
	void setY(int y);

	void moveLeft();
	void moveRight();
	void moveDown();

	void rotateClockwise();
	void rotateCounterClockwise();


private:
	static int instanceCount;

	ShapeTetriminos shape;
	const int id;
	int x, y;
};