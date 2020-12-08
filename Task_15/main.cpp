#include "Shape.h"
#include "Algorithm.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	Shape *a = new Square(24.22f);
	std::cout << "Square   |   Perimeter: " << a->perimeter() << "   Square: " << a->square() << std::endl;
	delete a;

	a = new Circle(10.111f);
	std::cout << "Circle   |   Perimeter: " << a->perimeter() << "   Square: " << a->square() << std::endl;
	delete a;

	a = new Rectangle(4.24f, 1.123f);
	std::cout << "Rectangle   |   Perimeter: " << a->perimeter() << "   Square: " << a->square() << std::endl;
	delete a;


	std::vector<double> v{ 11.111, 222.22 };
	std::list<int> l{ 1, 2, 3 };
	std::deque<float> d{ 10.1f, 11.2f, 12.1f };
	
	auto itv = myFind(v.begin(), v.end(), 222.22);
	auto itl = myFind(l.begin(), l.end(), 2);
	auto itd = myFind(d.rbegin(), d.rend(), 10.1f);
	std::cout << "Vector: " << *itv << "   |   List: " << *itl << "   |   Deque: " << *itd << std::endl;
	return 0;
}
