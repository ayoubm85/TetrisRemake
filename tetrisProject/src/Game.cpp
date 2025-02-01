#include "Game.hpp"
#include <random>
#include <iostream>
#include <format>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

Game::Game(Grid& grid)
	: grid(grid), isGameOver(false), isGamePaused(false), scoreText(font, ""), levelText(font, ""), pauseText(font, ""), gameOverText(font, ""), titleText(font, ""), infoText(font, ""), nextTetriminosText(font, "")
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

	levelText.setFont(font);
	levelText.setCharacterSize(30);
	levelText.setFillColor(Color::White);
	levelText.setPosition({ 400, 100 });

	pauseText.setFont(font);
	pauseText.setCharacterSize(30);
	pauseText.setFillColor(Color::White);
	pauseText.setPosition({ 400, 650 });
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

	nextTetriminosText.setFont(font);
	nextTetriminosText.setCharacterSize(20);
	nextTetriminosText.setFillColor(Color::White);
	nextTetriminosText.setPosition({ 400, 270 });
	nextTetriminosText.setString("NEXT TETRIMINOS");

	infoText.setFont(font);
	infoText.setCharacterSize(30);
	infoText.setFillColor(Color::White);
	infoText.setPosition({ 175, 730 });

	grid.resetGrid();
	currentTetriminos = generateRandomTetriminos();
	nextTetriminos = generateRandomTetriminos();

	dropInterval = grid.getScoreManager().getDropInterval();
}

Tetriminos Game::generateRandomTetriminos()
{
	static random_device rd;  
	static mt19937 gen(rd()); 
	uniform_int_distribution<> dis(0, SHAPES.size() - 1);
	const int randomIndex = dis(gen);
	const vector<vector<int>> randomShape = SHAPES[randomIndex];
	const Color randomColor = COLORS[randomIndex];
	const char randomId = SHAPES_IDS[randomIndex];
	return Tetriminos(ShapeTetriminos(randomShape, randomColor, randomId), 0, 3);
}

void Game::spawnTetriminos()	
{
	grid.clearFullLines();
	currentTetriminos = nextTetriminos;
	nextTetriminos = generateRandomTetriminos();
	checkGameOver();
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
	scoreManager.reset();
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
			spawnTetriminos();
		}
		dropClock.restart();
	}
}

void Game::renderNextTetriminos(sf::RenderWindow& window, const Tetriminos& nextTetriminos) 
{
	const auto& shape = nextTetriminos.getShape();
	const auto& color = shape.getColor();

	int gridSize = 4;
	int offsetX = 400;
	int offsetY = 300;

	int minX = 4, maxX = -1, minY = 4, maxY = -1;
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 4; ++j) 
		{
			if (shape.getShape()[i][j] == 1) 
			{
				if (i < minX) minX = i;
				if (i > maxX) maxX = i;
				if (j < minY) minY = j;
				if (j > maxY) maxY = j;
			}
		}
	}

	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			cell.setFillColor(sf::Color::Black); 
			cell.setOutlineColor(sf::Color::White);   
			cell.setOutlineThickness(1);              
			cell.setPosition({ static_cast<float>(offsetX + i * CELL_SIZE), static_cast<float>(offsetY + j * CELL_SIZE) });
			window.draw(cell);
		}
	}

	int tetriminosWidth = maxY - minY + 1;  
	int tetriminosHeight = maxX - minX + 1; 
	int centerX = (gridSize - tetriminosHeight) / 2;
	int centerY = (gridSize - tetriminosWidth) / 2;

	for (int i = 0; i < shape.getShape().size(); i++)
	{
		for (int j = 0; j < shape.getShape().size(); j++)
		{
			if (shape.getShape()[i][j] == 1)
			{
				sf::RectangleShape block(sf::Vector2f(CELL_SIZE, CELL_SIZE));
				block.setFillColor(color);
				block.setPosition({ static_cast<float>(offsetX + (centerY + j) * CELL_SIZE), static_cast<float>(offsetY + (centerX + i) * CELL_SIZE) });
				block.setOutlineColor(sf::Color::White); 
				block.setOutlineThickness(1);         

				window.draw(block);
			}
		}
	}
}


void Game::render() 
{
	window.clear();

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

	window.draw(nextTetriminosText);
	renderNextTetriminos(window, nextTetriminos);

	scoreText.setString(format("SCORE: {}", grid.getScoreManager().getScore()));
	levelText.setString(format("LEVEL: {}", grid.getScoreManager().getLevel()));
	

	window.draw(scoreText);
	window.draw(levelText);
	window.draw(titleText);
	window.draw(infoText);
	if (!isGamePaused && !isGameOver)
	{
		infoText.setString("Press SPACE to pause");
	}
	if (isGamePaused)
	{
		window.draw(pauseText);
		infoText.setString("Press SPACE to resume");
	}
	if (isGameOver)
	{
		window.draw(gameOverText);
		infoText.setString("Press SPACE to restart");
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