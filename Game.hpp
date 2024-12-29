#include "Constants.hpp"
#include "Grid.hpp"
#include "ScoreManager.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Game {
public:
	Game(Grid& grid, ScoreManager& scoreManager);
	~Game() = default;
	void initialize();
	void render();
	void run();

	Tetriminos generateRandomTetriminos();
	void spawnTetriminos();
	void fixActiveTetriminos();

	//void processGameInputs();
	void processInputs();
	void updateDropLogic();

	void pauseGame();
	void resumeGame();
	void resetGame();
	
	bool checkGameOver();
	void endGame();

private:
	Grid grid;
	ScoreManager scoreManager;
	sf::RenderWindow window;

	Tetriminos currentTetriminos;
	Tetriminos nextTetriminos;

	bool isGameOver;
	bool isGamePaused;

	float dropInterval;
	sf::Clock dropClock;

	sf::Font font;
	sf::Text scoreText, levelText, pauseText, gameOverText, titleText;
};