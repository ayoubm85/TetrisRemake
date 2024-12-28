#include "Constants.hpp"
#include "Grid.hpp"
#include "InputHandler.hpp"
#include "ScoreManager.hpp"


class Game {
public:
	Game(Grid& grid, InputHandler& inputHandler, ScoreManager& scoreManager);
	~Game() = default;
	void initialize();
	void render();
	void run();

	Tetriminos generateRandomTetriminos();
	void spawnTetriminos();
	void fixActiveTetriminos();

	void processInputs();
	void updateDropLogic();

	void pauseGame();
	void resumeGame();
	void resetGame();
	
	bool checkGameOver();
	void endGame();

private:
	Grid grid;
	InputHandler inputHandler;
	ScoreManager scoreManager;
	sf::RenderWindow window;

	Tetriminos currentTetriminos;
	Tetriminos nextTetriminos;

	bool isGameOver;
	bool isGamePaused;

	float dropInterval;
	sf::Clock dropClock;

	Font font;
	Text scoreText, levelText, pauseText, gameOverText, titleText;
};