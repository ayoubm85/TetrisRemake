#include "Game.hpp"
#include <random>


using namespace std;
using namespace sf;

Game::Game(Grid& grid, InputHandler& inputHandler, ScoreManager& scoreManager)
: grid(grid), inputHandler(inputHandler), scoreManager(scoreManager), isGameOver(false), isGamePaused(false) {
	initialize();
}

void Game::initialize() 
{
	window.create(VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Tetris");

	font.openFromFile("arial.ttf");

	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition({ 400, 50 });

	levelText.setFont(font);
	levelText.setCharacterSize(24);
	levelText.setFillColor(Color::White);
	levelText.setPosition({ 400, 100 });

	pauseText.setFont(font);
	pauseText.setCharacterSize(48);
	pauseText.setFillColor(Color::White);
	pauseText.setPosition({ 150, 200 });
	pauseText.setString("PAUSED");

	gameOverText.setFont(font);
	gameOverText.setCharacterSize(48);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition({ 100, 200 });
	gameOverText.setString("GAME OVER");

	titleText.setFont(font);
	titleText.setCharacterSize(48);
	titleText.setFillColor(Color::White);
	titleText.setPosition({ 100, 200 });
	titleText.setString("TETRIS");

	grid.resetGrid();
	currentTetriminos = generateRandomTetriminos();
	nextTetriminos = generateRandomTetriminos();

	scoreManager.resetScore();
	//InputHandler

	dropInterval = 0.5f;
	elapsedDropTime = 0.0f;
}

Tetriminos Game::generateRandomTetriminos()
{
	const int randomIndex = rand() % SHAPES.size();
	const vector<vector<int>> randomShape = SHAPES[randomIndex];
	const Color randomColor = COLORS[randomIndex];
	const char randomId = SHAPES_IDS[randomIndex];
	return Tetriminos(ShapeTetriminos(randomShape, randomColor, randomId), 0, 3);
}

void Game::spawnTetriminos()
{
	currentTetriminos = nextTetriminos;
	nextTetriminos = generateRandomTetriminos();
}

void Game::fixActiveTetriminos()
{

}

void Game::processInputs()
{

}

void Game::pauseGame()
{
	isGamePaused = true;
}

void Game::resumeGame()
{
	isGamePaused = false;
}

void Game::resetGame()
{
	grid.resetGrid();
	scoreManager.resetScore();
	scoreManager.resetLines();
	scoreManager.resetLevel();
	currentTetriminos = generateRandomTetriminos();
	nextTetriminos = generateRandomTetriminos();
	isGameOver = false;
	isGamePaused = false;
}

bool Game::checkGameOver()
{
	return grid.isGameOver(nextTetriminos);
}

void Game::endGame()
{
	isGameOver = true;
}

void Game::run()
{
	while (window.isOpen())
	{
		processInputs();
		if (!isGamePaused && !isGameOver)
		{

		}
	}
}