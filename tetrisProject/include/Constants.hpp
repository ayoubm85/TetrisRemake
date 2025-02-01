#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

constexpr int ROWS = 20;
constexpr int COLS = 10;
constexpr int CELL_SIZE = 30;
constexpr int EXTRA_WIDTH = 350;  
constexpr int EXTRA_HEIGHT = 200;
constexpr int WINDOW_HEIGHT = ROWS * CELL_SIZE + EXTRA_HEIGHT;
constexpr int WINDOW_WIDTH = COLS * CELL_SIZE + EXTRA_WIDTH;
constexpr sf::Color purple(134, 52, 235);

const vector<vector<int>> E = { {0, 0, 0, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

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

const vector<vector<int>> J = { {0, 0, 1, 0},
								{1, 1, 1, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<int>> L = { {1, 0, 0, 0},
								{1, 1, 1, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0} };

const vector<vector<vector<int>>> SHAPES = { I, O, T, S, Z, J, L };

const vector<sf::Color> COLORS = { sf::Color::Cyan, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Red, sf::Color::Green, sf::Color::Blue, purple };

const vector<char> SHAPES_IDS = { 'I', 'O', 'T', 'S', 'Z', 'J', 'L' };
