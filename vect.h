//vect.h -- class Vector with << operation and coordinates mood support

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {RECT, POL};
	private:
		double x, y;				//Coordinates value
		double mag, ang;			//length and direction(route) of vector
		Mode mode;

		void SetMag();
		void SetAng();
		void SetX();
		void SetY();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		double GetX() const {return x;};
		double GetY() const {return y;};
		double GetMag() const {return mag;};
		double GetAng() const {return ang;};
		void SetPolar();
		void SetRect();

		Vector operator+(const Vector & other) const;
		Vector operator-(const Vector & other) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector & other);
		friend std::ostream & operator<<(std::ostream & os, const Vector & other);
	};
}

#endif
