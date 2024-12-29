#include "Game.hpp"
#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Game::Game(Grid& grid, ScoreManager& scoreManager)
	: grid(grid), scoreManager(scoreManager), isGameOver(false), isGamePaused(false), scoreText(font, ""), levelText(font, ""), pauseText(font, ""), gameOverText(font, ""), titleText(font, ""), font()
{
	initialize();
}

void Game::initialize() 
{
	window.create(VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Tetris");

	font.openFromFile("C:\\Users\\amarf\\Desktop\\ProjetTetris\\tetrisProject\\x64\\Debug\\8514oem.ttf");

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

	dropInterval = 0.5f;
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
	if (checkGameOver())
	{
		endGame();
	}
}

void Game::fixActiveTetriminos()
{
	grid.clearFullLines();
	spawnTetriminos();
	if (checkGameOver()) {
		endGame();
	}
}

void Game::processInputs()
{
	while (const optional event = window.pollEvent())
	{
		if (event->is<Event::Closed>())
		{
			window.close();
		}
		else if (event->is<Event::KeyPressed>()) 
		{
			if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Space)
			{
				isGamePaused = !isGamePaused;
			}
			else if (!isGamePaused && !isGameOver)
			{
				if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Left)
				{
					if (grid.isValidMove(currentTetriminos, 0, -1))
						currentTetriminos.moveLeft();
				}
				else if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Right)
				{
					if (grid.isValidMove(currentTetriminos, 0, 1))
						currentTetriminos.moveRight();
				}
				else if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Down)
				{
					if (grid.isValidMove(currentTetriminos, 1, 0))
						currentTetriminos.moveDown();
				}
				else if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::L)
				{
					Tetriminos tempCurrentTetriminos = currentTetriminos;

					if (grid.isValidMove(tempCurrentTetriminos, 1, 1))
						currentTetriminos.rotateClockwise();
				}
				else if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::J)
				{
					Tetriminos tempCurrentTetriminos = currentTetriminos;

					if (grid.isValidMove(tempCurrentTetriminos, 1, 1))
						currentTetriminos.rotateCounterClockwise();
				}
				grid.updateGrid(currentTetriminos, &window);
			}
			
		}
	}
}

void Game::pauseGame()
{
	isGamePaused = true;
	window.draw(pauseText);
}

void Game::resumeGame()
{
	isGamePaused = false;
}

void Game::resetGame()
{
	isGameOver = false;
	isGamePaused = false;
	grid.resetGrid();
	//scoreManager.resetScore();
	//scoreManager.resetLines();
	//scoreManager.resetLevel();
	currentTetriminos = generateRandomTetriminos();
	nextTetriminos = generateRandomTetriminos();
}

bool Game::checkGameOver()
{
	return grid.isGameOver(currentTetriminos);
}

void Game::endGame()
{
	isGameOver = true;
	window.draw(gameOverText);
	cout << "Game Over" << endl;
}

void Game::updateDropLogic()
{
	if (dropClock.getElapsedTime().asSeconds() >= dropInterval)
	{
		if (grid.isValidMove(currentTetriminos, 1, 0))
		{
			currentTetriminos.moveDown();
			grid.updateGrid(currentTetriminos, &window);
		}
		else
		{
			fixActiveTetriminos();
		}
		dropClock.restart();
	}
}

void Game::render() 
{
	window.clear();

	grid.addTetriminosToGrid(currentTetriminos);
	grid.drawGrid(&window);
	window.draw(scoreText);
	window.draw(levelText);
	window.draw(titleText);
}

void Game::run()
{
	dropClock.start();
	while (window.isOpen())
	{
		processInputs();
		if (!isGamePaused && !isGameOver)
		{
			updateDropLogic();
		}
		while (isGameOver && !isGamePaused)
		{
			processInputs();
			if (isGamePaused) 
			{
				resetGame();
			}
		}
		render();
		window.display();
	}
}