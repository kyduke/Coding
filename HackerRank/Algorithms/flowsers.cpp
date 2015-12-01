// https://www.hackerrank.com/challenges/flowers

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Customer {
	int cost;
	vector<int> flowsers;
	void addFlowser(int f) {
		int i;

		flowsers.push_back(f);
		for (i = 0; i < flowsers.size(); i++) {
			cost += flowsers[i];
		}
	}
	bool operator< (const Customer& a) const {
		if (cost == a.cost) return flowsers.size() > a.flowsers.size();
		return cost > a.cost;
	}
};

int solve(int n, int k, vector<int>& costs) {
	priority_queue<Customer> customers;
	Customer c;
	int i, ret;

	sort(costs.begin(), costs.end());

	c.cost = 0;
	c.flowsers.clear();
	for (i = 0; i < k; i++) {
		customers.push(c);
	}

	i = 0;
	while (i < n) {
		c = customers.top();
		customers.pop();
		c.addFlowser(costs[i]);
		customers.push(c);
		i++;
	}

	ret = 0;
	while (!customers.empty()) {
		ret += customers.top().cost;
		customers.pop();
	}

	return ret;
}

int main(int argc, char* argv[]) {
	vector<int> costs;
	int n, k;

	cin >> n >> k;
	costs.assign(n, 0);

	while (n--) {
		cin >> costs[n];
	}

	cout << solve(costs.size(), k, costs) << "\n";

	return 0;
}

/*
3 3
2 5 6
=====
13

3 2
2 5 6
=====
15
*/
