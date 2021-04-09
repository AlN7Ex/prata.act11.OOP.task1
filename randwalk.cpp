// randwalk.cpp -- use class Vector
// Compile with vect.cpp

#include "vect.h"

#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	ofstream fout;
	fout.open("file.txt");
	srand(time(NULL));

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
		{
			break;
		}
		fout << "Target distance: " << target << ", Step size: " << dstep << endl;
		fout << endl;
		while (result.GetMag() < target)
		{
			std::cout << "GetMag(): " << result.GetMag() << std::endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			fout << steps << ":\t" << result << endl;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the following location: " << endl;
		cout << result << endl;
		result.SetPolar();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.GetMag() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
		fout << endl;
	}
	fout.close();
	cout << "Bye!" << endl;
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}