#include "Shape.hpp"

ShapeTetriminos::ShapeTetriminos(const std::vector<std::vector<int>>& shape, const sf::Color color, const char id) : shape(shape), color(color), id(id) {}

const std::vector<std::vector<int>>& ShapeTetriminos::getShape() const {
	return shape;
}

char ShapeTetriminos::getId() const {
	return id;
}

sf::Color ShapeTetriminos::getColor() const {
	return color;
}

