#include "stdafx.h"
#include "Object.h"

Object::Object()
{
}

Object::Object(int width, int height) : width(width), height(height)
{
}

Object::~Object()
{
}

void Object::rotate(Object& dst) const
{
	dst.clear();
	dst.width = height;
	dst.height = width;

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			dst.at(height - y - 1, x) = at(x, y);
		}
	}
}

void Object::print() const
{
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			std::cout << at(x, y);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}