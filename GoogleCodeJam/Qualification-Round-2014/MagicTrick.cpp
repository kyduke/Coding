#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int T, i, R, j, k, match, temp;
	int first[4], second[4];

	cin >> T;
	i = 0;
	while (i < T)
	{
		cin >> R;
		R--;
		for (j = 0; j < 16; j++)
		{
			cin >> temp;
			if ((j / 4) == R) first[j % 4] = temp;
		}

		cin >> R;
		R--;
		for (j = 0; j < 16; j++)
		{
			cin >> temp;
			if ((j / 4) == R) second[j % 4] = temp;
		}

		cout << "Case #" << ++i << ": ";

		temp = 0;
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				if (first[j] == second[k]) 
				{
					temp++;
					match = first[j];
				}
			}
		}

		if (temp == 0)
		{
			cout << "Volunteer cheated!";
		}
		else if (temp > 1)
		{
			cout << "Bad magician!";
		}
		else
		{
			cout << match;
		}

		cout << "\n";
	}

	return 0;
}

/*
3
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
=====
Case #1: 7
Case #2: Bad magician!
Case #3: Volunteer cheated!
*/
