#include "Constants.hpp"
#include "Tetriminos.hpp"

class Grid {
public:
	Grid();
	~Grid() = default;
	void setCell(int x, int y, char tetriminosType);
	char getCell(int x, int y);
	void drawGrid(sf::RenderWindow* window);
	void addTetriminosToGrid(const Tetriminos& tetriminos);

private:
	char grid[ROWS][COLS];
};