#include <iostream>
#include <vector>

using namespace std;

void makeNextSequence(vector<int>& sequence) {
	vector<int> copy;
	int i, n, c;

	copy = sequence;
	sequence.clear();

	n = copy[0];
	c = 1;
	for (i = 1; i < copy.size(); i++) {
		if (copy[i] == n) {
			c++;
		} else {
			sequence.push_back(c);
			sequence.push_back(n);
			n = copy[i];
			c = 1;
		}
	}
	sequence.push_back(c);
	sequence.push_back(n);
}

void printSequence(vector<int> sequence) {
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i];
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	vector<int> sequence;
	int i, j;

	sequence.push_back(1);
	printSequence(sequence);

	for (i = 0; i < 10; i++) {
		makeNextSequence(sequence);
		printSequence(sequence);
	}

	return 0;
}
