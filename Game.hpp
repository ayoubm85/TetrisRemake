#include "Constants.hpp"
#include "Grid.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Game {
public:
	Game(Grid& grid);
	~Game() = default;
	void initialize();
	void render();
	void run();

	Tetriminos generateRandomTetriminos();
	void spawnTetriminos();

	void processInputs();
	void updateDropLogic();

	void resetGame();
	
	void checkGameOver();

	void renderNextTetriminos(sf::RenderWindow& window, const Tetriminos& nextTetriminos);

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
	sf::Text scoreText, levelText, pauseText, gameOverText, titleText, infoText, nextTetriminosText;
};