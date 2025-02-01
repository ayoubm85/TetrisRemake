#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>   
#include <iostream>
#include "Grid.hpp"
#include "Game.hpp"

using namespace sf;
using namespace std;

int main()
{
	ScoreManager* scoreManager = new ScoreManager();
	Grid* grid = new Grid(50, 100, *scoreManager);
	Game* game = new Game(*grid);



	game->run();

	delete game;
	delete grid;
	delete scoreManager;

    return 0;
}