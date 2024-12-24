#include "Constants.hpp"


class Shape {
public:
	Shape(std::vector<std::vector<int>>& shape, sf::Color color);
	~Shape();
	std::vector<std::vector<int>> shape;
	sf::Color color;

};