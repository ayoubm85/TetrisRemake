#pragma once
#include "Constants.hpp"
#include "Tetriminos.hpp"
#include "ScoreManager.hpp"

class Grid {
public:
	Grid(int offsetX, int offsetY, ScoreManager scoreManager);
	~Grid() = default;

	void setCell(int x, int y, string tetriminosType);
	string getCell(int x, int y);

	ScoreManager getScoreManager() const;

	void drawGrid(sf::RenderWindow* window);
	void addTetriminosToGrid(const Tetriminos& tetriminos);
	void updateGrid(const Tetriminos& tetriminos, sf::RenderWindow* window);

	bool isValidMove(const Tetriminos& tetriminos, int x, int y);
	void clearFullLines();

	void resetGrid();
	bool isGameOver(const Tetriminos& nextTetriminos);

private:
	string grid[ROWS][COLS];
	int offsetX, offsetY;
	ScoreManager scoreManager;
};