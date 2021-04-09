//vect.cpp -- methods of class Vector

#include <cmath>
#include "vect.h"

using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::endl;
using std::sqrt;
using std::sin;


namespace VECTOR
{
	const double RadToDeg = 45.0 / atan(1.0);

	void Vector::SetMag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::SetAng()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	void Vector::SetX()
	{
		x = mag * cos(ang);
	}

	void Vector::SetY()
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;

		if (form == RECT)
		{
			x = n1;
			y = n2;
			SetMag();
			SetAng();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / RadToDeg;
			SetX();
			SetY();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() " << endl;
			cout << "Vector set to 0.0" << endl;
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;

		if (form == RECT)
		{
			x = n1;
			y = n2;
			SetMag();
			SetAng();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / RadToDeg;
			SetX();
			SetY();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() " << endl;
			cout << "Vector set to 0.0" << endl;
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::SetRect()
	{
		mode = RECT;
	}

	void Vector::SetPolar()
	{
		mode = POL;
	}

	Vector Vector::operator+(const Vector & other) const
	{
		return Vector(x + other.x, y + other.y);
	}

	Vector Vector::operator-(const Vector & other) const
	{
		return Vector(y - other.y, y - other.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	Vector operator*(double n, const Vector & other)
	{
		return other * n;
	}

	std::ostream & operator<<(std::ostream & os, const Vector & other)
	{
		if (other.mode == Vector::RECT)
		{
			os << "(x, y) = (" << other.x << ", " << other.y << ")";
		}
		else if (other.mode == Vector::POL)
		{
			os << "(m, a) = (" << other.mag << ", " << other.ang * RadToDeg << ")";
		}
		else
		{
			os << "Vector object mode is invalid";
		}
		return os;
	}
}