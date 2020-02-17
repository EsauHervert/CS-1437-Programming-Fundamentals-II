// Esau Hervert
// COSC 1437
// Project 5, problem 1.
// Options/References: None.

#include <iostream>

using namespace std;

// The abstract class.
class BasicShape
{
protected:
	double area;

public:
	double getArea()
	{
		return area;
	}

	virtual void calcArea() = 0;
};

class Circle : public BasicShape
{
private:
	long centerX;
	long centerY;
	double radius;
	const double Pi = 3.14159;

public:
	Circle(long X, long Y, double R) // Constructor.
	{
		centerX = X;
		centerY = Y;
		radius = R;
		calcArea();
	}

	long getCenterX()
	{
		return centerX;
	}

	long getCenterY()
	{
		return centerY;
	}

	// Defining the method.
	virtual void calcArea()
	{
		area = Pi * radius * radius;
	}
};

class Rectangle : public BasicShape
{
private:
	long length;
	long width;

public:
	Rectangle(long L, long W) // Constructor.
	{
		length = L;
		width = W;
		calcArea();
	}

	long getLength()
	{
		return length;
	}

	long getWidth()
	{
		return width;
	}

	// Defining the method.
	virtual void calcArea()
	{
		area = length * width;
	}
};

int main()
{
	// Circle.
	long Xcoor, Ycoor;
	double rad;

	// Rectangle.
	long wid, len;

	//*********************************************************************************************
	// Inforamation for the Circle.

	cout << "Please enter the x coordinate of the circle's center: ";
	cin >> Xcoor;

	cout << "Please enter the y coordinate of the circle's center: ";
	cin >> Ycoor;

	cout << "Please enter the radius of the circle: ";
	cin >> rad;

	Circle circle(Xcoor, Ycoor, rad);

	cout << "The area of the circle is " << circle.getArea() << endl << endl;
	//*********************************************************************************************

	//*********************************************************************************************
	//Rectangle.

	cout << "Please enter the length of the rectangle: ";
	cin >> len;

	cout << "Please enter the width of the rectangle: ";
	cin >> wid;

	Rectangle rectangle(len, wid);

	cout << "The area of the rectangle is " << rectangle.getArea() << endl;
	//*********************************************************************************************

	return 0;
}