#include <iostream>
#include <stdio.h>

using namespace std;

double solve(double C, double F, double X)
{
	double rate, next, min, temp;

	rate = 2.0;
	min = X / rate;
	next = 0;

	while (1)
	{
		next += C / rate;
		rate += F;
		temp = next + X / rate;
		if (temp < min)
		{
			min = temp;
		}
		else
		{
			break;
		}
	}	

	return min;
}

int main(int argc, char* argv[])
{
	int T, i;
	double C, F, X;

	cin >> T;
	i = 0;
	while (i < T)
	{
		i++;
		cin >> C >> F >> X;

		cout << "Case #" << i << ": ";

		printf("%.7f", solve(C, F, X));

		cout << "\n";
	}

	return 0;
}

/*
4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0
=====
Case #1: 1.0000000
Case #2: 39.1666667
Case #3: 63.9680013
Case #4: 526.1904762
*/
