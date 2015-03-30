#include <iostream>
#include <vector>

using namespace std;

class CountryGroup {
public:
	int solve(vector<int> a) {
		int countries, people, current, i, l;

		countries = 0;
		people = 0;
		l = a.size();
		for (i = 0; i < l; i++) {
			if (people == 0) {
				current = a[i];
				people = current - 1;
				countries++;
				continue;
			}

			if (current != a[i]) return -1;

			people--;
		}

		if (people != 0) return -1;

		return countries;
	}
};

int main(int argc, char* argv[]) {
	CountryGroup cg;
	vector<int> a;

	a.clear();
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);

	cout << cg.solve(a) << "\n";

	a.clear();
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);

	cout << cg.solve(a) << "\n";

	a.clear();
	a.push_back(3);
	a.push_back(3);

	cout << cg.solve(a) << "\n";

	a.clear();
	a.push_back(4);
	a.push_back(4);
	a.push_back(4);
	a.push_back(4);
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);

	cout << cg.solve(a) << "\n";

	a.clear();
	a.push_back(2);
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(1);
	a.push_back(2);

	cout << cg.solve(a) << "\n";

	return 0;
}

/*
2 2 3 3 3
=====
2

1 1 1 1 1
=====
5

3 3
=====
-1

4 4 4 4 1 1 2 2 3 3 3
=====
5

2 1 2 2 1 2
=====
-1
*/
