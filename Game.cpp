#include "Game.hpp"
#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Game::Game(Grid& grid, ScoreManager& scoreManager)
	: grid(grid), scoreManager(scoreManager), isGameOver(false), isGamePaused(false), scoreText(font, ""), levelText(font, ""), pauseText(font, ""), gameOverText(font, ""), titleText(font, "")
{
	initialize();
}

void Game::initialize() 
{
	window.create(VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Tetris");

	font.openFromFile("arial.ttf");
	

	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition({ 400, 150 });
	scoreText.setString("SCORE: 0");

	levelText.setFont(font);
	levelText.setCharacterSize(30);
	levelText.setFillColor(Color::White);
	levelText.setPosition({ 400, 100 });
	levelText.setString("LEVEL: 1");

	pauseText.setFont(font);
	pauseText.setCharacterSize(30);
	pauseText.setFillColor(Color::White);
	pauseText.setPosition({ 400, 615 });
	pauseText.setString("PAUSED");

	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition({ 400, 650 });
	gameOverText.setString("GAME OVER");

	titleText.setFont(font);
	titleText.setCharacterSize(48);
	titleText.setFillColor(Color::White);
	titleText.setPosition({ 250, 20 });
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
	checkGameOver();
}

void Game::fixActiveTetriminos()
{
	grid.clearFullLines();
	spawnTetriminos();
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

void Game::checkGameOver()
{
	if (grid.isGameOver(currentTetriminos))
	{
		isGameOver = true;
	}
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
	cout << "rendering" << endl;
	window.clear();
	/*sf::Texture windowTexture("abstract_pixel_design_3.jpg");*/
	sf::Texture windowTexture("pixel_backround.jpg");
	sf::Sprite windowBackground(windowTexture);
	windowBackground.setScale(
		{	static_cast<float>(WINDOW_WIDTH) / windowTexture.getSize().x,
			static_cast<float>(WINDOW_HEIGHT) / windowTexture.getSize().y 
		}
	);
	window.draw(windowBackground);
	grid.addTetriminosToGrid(currentTetriminos);
	grid.drawGrid(&window);
	window.draw(scoreText);
	window.draw(levelText);
	window.draw(titleText);
	if (isGamePaused)
	{
		window.draw(pauseText);
	}
	if (isGameOver)
	{
		cout << "game over" << endl;
		window.draw(gameOverText);
	}
	window.display();
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
			render();
			processInputs();
			if (isGamePaused) 
			{
				resetGame();
			}
		}
		render();
	}
}