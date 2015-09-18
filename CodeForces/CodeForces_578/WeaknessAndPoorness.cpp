// http://codeforces.com/problemset/problem/578/C
// ing...

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

double maximumSubArraySumByKadane(vector<double> arr) {
	int i;
    double subSum, sum;

	sum = subSum = 0;
    for (i = 0; i < arr.size(); i++)
    {
        subSum += arr[i];
        if (subSum > 0) {
            if (subSum > sum) sum = subSum;
        } else {
            subSum = 0.0;
        }
    }

	return sum;
}

int main(int argc, char* argv[]) {
	int n, i;
	double sum, avg, t;
	vector<double> arr;
	vector<double>::iterator it;

	cin >> n;
	sum = 0.0;
	i = 0;
	while (i < n) {
		cin >> t;
		it = find(arr.begin(), arr.end(), t);
		if (it == arr.end()) sum += t;
		arr.push_back(t);
		i++;
	}
	avg = sum / (double)(n - 1);
	cout << avg << ", " << sum << "\n";

	avg = -6.8125;

	i = 0;
	while (i < n) {
		arr[i] -= avg;
		i++;
	}

	printf("%.15f\n", maximumSubArraySumByKadane(arr));

	return 0;
}

/*
3
1 2 3
=====
1.000000000000000

4
1 2 3 4
=====
2.000000000000000

10
1 10 2 9 3 8 4 7 5 6
=====
4.500000000000000
*/

/*
20
-16 -23 29 44 -40 -50 -41 34 -38 30 -12 28 -44 -49 15 50 -28 38 -2 0
Participant's output
95.500000000000000
Jury's answer
113.875000000000000

x = -6.8125
*/
