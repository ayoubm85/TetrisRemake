#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>   
#include <iostream>
#include "Grid.hpp"
#include "Game.hpp"

using namespace sf;
using namespace std;

int main()
{
	Grid grid;
	ScoreManager scoreManager;
	Game game(grid, scoreManager);

	game.run();


    return 0;
}