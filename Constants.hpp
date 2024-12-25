#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

constexpr int ROWS = 20;
constexpr int COLS = 10;
constexpr int CELL_SIZE = 30;
constexpr int WINDOW_HEIGHT = ROWS * CELL_SIZE;
constexpr int WINDOW_WIDTH = COLS * CELL_SIZE;

const vector<vector<int>> I = { {0, 1, 0, 0},
								{0, 1, 0, 0},
								{0, 1, 0, 0},
								{0, 1, 0, 0} };

const vector<vector<int>> O = { {1, 1, 0, 0},
								{1, 1, 0, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<int>> T = { {0, 1, 0, 0},
								{1, 1, 1, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<int>> S = { {0, 1, 1, 0},
								{1, 1, 0, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<int>> Z = { {1, 1, 0, 0},
								{0, 1, 1, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<int>> J = { {1, 0, 0, 0},
								{1, 1, 1, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<int>> L = { {0, 0, 1, 0},
								{1, 1, 1, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<vector<int>>> SHAPES = { I, O, T, S, Z, J, L };

const vector<sf::Color> COLORS = { sf::Color::Cyan, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::White };

