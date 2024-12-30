#include "Constants.hpp"
#include "Grid.hpp"
#include "ScoreManager.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


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

	void processInputs();
	void updateDropLogic();

	void resetGame();
	
	void checkGameOver();

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

/*	sf::Texture windowTexture;
	sf::Sprite windowBackground*/;
};