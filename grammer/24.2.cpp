/*2022年11月16日23:06:58
随机行走*/
#include <iostream>
#include <cstdlib>//为了使用随机数
#include <ctime>
#include "24.h"

int main(void)
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0, 0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "enter target distance (q to quit)";
	while (cin >> target)
	{
		cout << "enter step length";
		if (!(cin >> dstep))
			break;
		while (result.lenval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		cout << "after " << steps << "steps,the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		cout << "average outward distance per step ="
			<< result.lenval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "enter target distance (q to quit):";
	}
	cout << "bye!\n";
	return 0;
}