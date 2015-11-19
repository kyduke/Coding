// http://careercup.com/question?id=5667288701206528

#include <iostream>
#include <vector>

using namespace std;

typedef long long INT64;

void minimumDividableSum(vector<int>& arr, int K, int F, int idx, INT64 sum, INT64& answer) {
	if (K == 0) {
		if (sum != 0 && sum % F == 0 && (answer == -1 || answer > sum)) {
			answer = sum;
		}
		return;
	}

	if (answer != -1 && sum > answer) return;
	if (idx >= arr.size()) return;

	minimumDividableSum(arr, K - 1, F, idx + 1, sum + arr[idx], answer);
	minimumDividableSum(arr, K, F, idx + 1, sum, answer);
}

INT64 solve(vector<int>& arr, int K, int F) {
	INT64 answer = -1;

	if (K > arr.size()) return answer;

	minimumDividableSum(arr, K, F, 0, 0, answer);

	return answer;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	int data[] = {1, 2, 3, 4, 5};
	int answer = -1;

	arr.assign(data, data + 5);

	cout << solve(arr, 3, 5) << "\n";

	return 0;
}
