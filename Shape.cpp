#include "Shape.hpp"

Shape::Shape(std::vector<std::vector<int>>& shape, sf::Color color) : shape(shape), color(color) {}

Shape::~Shape() = default;