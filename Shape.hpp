#pragma once
#include "Constants.hpp"


class ShapeTetriminos {
public:
	ShapeTetriminos(const std::vector<std::vector<int>>& shape, const sf::Color color, const char id);
	~ShapeTetriminos() = default;
	const std::vector<std::vector<int>>& getShape() const;
	char getId() const;
	sf::Color getColor() const;

private:
	char id;
	std::vector<std::vector<int>> shape;
	sf::Color color;
};