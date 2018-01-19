#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

class Shape
{
public:
	virtual void show() = 0;
	virtual void showArea() = 0;
	virtual double getArea() = 0;
};

class Square : public Shape
{
public:
	Square(const unsigned int side)
	{
		this->side = side;
	}
	void setParameters(const unsigned int side)
	{
		this->side = side;
	}
	void show()
	{
		cout << "Side length = " << side << endl;
	}
	double getArea()
	{
		return side * side;
	}
	void showArea()
	{
		cout << "Square Area = " << side * side << endl;
	}
private:
	unsigned int side;
};

class Rectangle : public Shape
{
public:
	Rectangle(const unsigned int side, const unsigned int height)
	{
		this->width = side;
		this->height = height;
	}
	void setParameters(const unsigned int side, const unsigned int height)
	{
		this->width = side;
		this->height = height;
	}
	void show()
	{
		cout << "Side length = " << width << endl << "Height = " << height << endl;
	}
	double getArea()
	{
		return width * height;
	}
	void showArea()
	{
		cout << "Square Area = " << width * height << endl;
	}
	~Rectangle()
	{
		cout << "~Rectangle()" << endl;
	}
private:
	unsigned int width;
	unsigned int height;
};

int main(int argv, char *argc[])
{
	//Shape &&a = Rectangle(10,20);

	Shape *shape[] = { new Square(5), new Rectangle(5,10) };
	vector<Shape> svec;
	for (auto beg = begin(shape), E = end(shape); beg != E; ++beg)
	{
		if (*beg != nullptr)
		{
			(*beg)->showArea();
			delete *beg;
			*beg = nullptr;
		}
	}
	for (Shape *temp : shape)
	{
		cout << temp << endl;
	}

	system("pause");
	return 0;
}