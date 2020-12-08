#include "Shape.h"

Shape::~Shape()
{}

Circle::Circle(float radius)
	: _radius(radius)
{}

float Circle::perimeter()
{
	return _radius * PI * 2;	
}

float Circle::square()
{
	return PI * _radius * _radius;
}

Square::Square(float a)
	: _a(a)
{}

float Square::perimeter()
{
	return _a * 4;
}

float Square::square()
{
	return _a * _a;
}

Rectangle::Rectangle(float a, float b)
	: _a(a), _b(b)
{}

float Rectangle::perimeter()
{
	return (2 * _a) + (2 * _b);
}

float Rectangle::square()
{
	return _a * _b;
}

