#include <SFML/Graphics.hpp>

constexpr int ROWS = 20;
constexpr int COLS = 10;
constexpr float CELL_SIZE = 30;

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