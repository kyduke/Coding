// http://codeforces.com/contest/606/problem/E

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	double a;
	double b;
	int cnt;
	int idx;
};

int main(int argc, char* argv[]) {
	vector<double> arrA, arrB;
	double minCost, temp, tempA, tempB, p, q, na, nb;
	queue<Node> qq;
	Node node;
	int n, a, b, i;

	cin >> n >> a >> b;
	p = (double)a;
	q = (double)b;
	while (n--) {
		cin >> a >> b;
		arrA.push_back((double)a);
		arrB.push_back((double)b);
	}

	for (i = 0; i < arrA.size(); i++) {
		node.a = arrA[i];
		node.b = arrB[i];
		node.cnt = 1;
		node.idx = i + 1;
		qq.push(node);
	}

	minCost = 1000000.0;
	while (!qq.empty()) {
		node = qq.front();
		qq.pop();
		na = node.a;
		nb = node.b;
		tempA = p / na;
		tempB = q / nb;
		if (tempA > tempB) {
			temp = tempA * node.cnt;
		} else {
			temp = tempB * node.cnt;
		}
		if (minCost > temp) minCost = temp;
		
		node.cnt++;
		for (i = node.idx; i < arrA.size(); i++) {
			node.a = na + arrA[i];
			node.b = nb + arrB[i];
			node.idx = i + 1;
			qq.push(node);
		}
	}

	printf("%.15f\n", minCost);

	return 0;
}

/*
3 20 20
6 2
1 3
2 6
=====
5.000000000000000

4 1 1
2 3
3 2
2 3
3 2
=====
0.400000000000000
*/
