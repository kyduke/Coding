// http://careercup.com/question?id=5686055997014016

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nthMultipleNumber(vector<int> arr, int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int i, ret;

	if (arr.size() == 0 || n <= 0) return 0;

	for (i = 0;i < arr.size(); i++) {
		q.push(make_pair(arr[i], i));
	}

	ret = 0;
	while (n) {
		if (ret != q.top().first) n--;
		ret = q.top().first;
		i = q.top().second;
		q.pop();
		q.push(make_pair(ret + arr[i], i));
	}

	return ret;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	int data[] = {4, 6};

	arr.assign(data, data + 2);
	cout << nthMultipleNumber(arr, 6) << "\n";
	cout << nthMultipleNumber(arr, 0) << "\n";
	cout << nthMultipleNumber(arr, 1) << "\n";
	cout << nthMultipleNumber(arr, 2) << "\n";
	cout << nthMultipleNumber(arr, 3) << "\n";

	return 0;
}
