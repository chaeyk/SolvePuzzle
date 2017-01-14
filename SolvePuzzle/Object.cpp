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

void Object::put(const char* shape, char id)
{
	size_t len = strlen(shape);
	if (len > sizeof(bytes)) {
		std::cerr << "too big shape." << std::endl;
		exit(1);
	}
	if (len != width * height) {
		std::cerr << "invalid shape." << std::endl;
		exit(1);
	}

	for (int i = 0; i < len; ++i) {
		if (shape[i] == '0')
			bytes[i] = '0';
		else
			bytes[i] = id;
	}
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