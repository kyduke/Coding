// http://www.careercup.com/question?id=5696520106016768

#include <iostream>
#include <queue>
#include <set>

using namespace std;

class MaxInWindow {
private:
	queue<int> orderByInput;
	multiset<int> orderByValue;
public:
	int findMaxInWindow(int windowSize, int value) {
		orderByInput.push(value);
		orderByValue.insert(value);

		if (orderByInput.size() > windowSize) {
			orderByValue.erase( orderByInput.front() );
			orderByInput.pop();
		}

		return *orderByValue.rbegin();
	}
};

int main(int argc, char* argv[]) {
	MaxInWindow mw;
	int arr[] = {1, 4, 2, 7, 9, 15, 11, 26, 96, 56, 3, 15, 25};
	int i;

	for (i = 0; i < 13; i++) {
		cout << mw.findMaxInWindow(3, arr[i]) << "\n";
	}

	return 0;
}
