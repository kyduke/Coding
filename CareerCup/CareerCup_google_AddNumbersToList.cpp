// http://www.careercup.com/question?id=5717521992777728

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> addNumbersToList(int n, vector<int>& arr) {
	vector<int> answer;
	set<int> result, temp, copyArr;
	set<int>::iterator it, itResult;
	int i, target, x, t;

	if (n == 0) return answer;

	result.insert(n + 1);

	i = 0;
	while (i < arr.size()) {
		temp.clear();
		it = result.begin();
		while (it != result.end()) {
			temp.insert(*it + arr[i]);
			it++;
		}
		it = temp.begin();
		while (it != temp.end()) {
			result.insert(*it);
			it++;
		}
		result.insert(arr[i]);
		copyArr.insert(arr[i]);
		i++;
	}

	target = 1;
	itResult = result.begin();
	while (itResult != result.end()) {
		if (*itResult == target) {
			if (target == n) break;
			itResult++;
			target++;
			continue;
		}
		x = target;
		it = result.begin();
		while (it != result.end()) {
			if (*it >= target) break;
			t = target - *it;
			if (x > t && copyArr.find(t) == copyArr.end()) {
				x = t;
			}
			it++;
		}

		copyArr.insert(x);
		answer.push_back(x);

		temp.clear();
		it = result.begin();
		while (it != result.end()) {
			temp.insert(*it + x);
			it++;
		}
		it = temp.begin();
		while (it != temp.end()) {
			result.insert(*it);
			it++;
		}
		result.insert(x);
		itResult = result.find(target);

		itResult++;
		target++;
	}

	return answer;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	vector<int> answer;
	int i;

	arr.push_back(1);
	arr.push_back(3);

	answer = addNumbersToList(6, arr);
	for (i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";

	arr.clear();
	answer = addNumbersToList(10, arr);
	for (i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";

	return 0;
}
