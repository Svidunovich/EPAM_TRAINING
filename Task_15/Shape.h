#ifndef SHAPE_H
#define SHAPE_H

const auto PI = 3.145;

class Shape
{
	public:
		virtual float perimeter() = 0;
		virtual float square() = 0;
		virtual ~Shape();
};

class Circle : public Shape
{
	public:
		Circle(float radius = float());
		float perimeter() override;	
		float square() override;
	private:
		float _radius;
};

class Square : public Shape
{
	public:
		Square(float a = float());
		float perimeter() override;
		float square() override;
	private:
		float _a;
};

class Rectangle : public Shape
{
	public:
		Rectangle(float a = float(), float b = float());
		float perimeter() override;
		float square() override;
	private:
		float _a;
		float _b;
};

#endif
