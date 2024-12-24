#include "Constants.hpp"

class Grid {
public:
	Grid();
	~Grid();
	void setCell(int x, int y, int color);
	int get(int x, int y);
	void draw(sf::RenderWindow* window);

private:
	int grid[ROWS][COLS];
};