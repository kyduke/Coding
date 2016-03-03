// https://leetcode.com/problems/reconstruct-itinerary/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
	struct Compare {
		bool operator() (const pair<string, string>& a, const pair<string, string>& b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first < b.first;
		}
	};
	struct Node {
		int current;
		bool processed;
	};
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
		stack<Node> s;
		Node node;
		vector<int> visit;
        vector<string> result;
		string from;
		int i;

		sort(tickets.begin(), tickets.end(), Compare());

		result.push_back("JFK");

		visit.assign(tickets.size(), 0);
		node.current = 0;
		node.processed = false;
		s.push(node);

		while (!s.empty()) {
			node = s.top();
			s.pop();

			if (node.current >= tickets.size()) continue;

			if (node.processed == false) {
				if (visit[ node.current ] == 1) {
					node.current++;
					s.push(node);
				} else {
					from = *result.rbegin();
					if (tickets[ node.current ].first == from) {
						visit[ node.current ] = 1;
						result.push_back(tickets[ node.current ].second);
						if (result.size() > tickets.size()) {
							return result;
						}
						node.processed = true;
						s.push(node);

						node.current = 0;
						node.processed = false;
						s.push(node);
					} else {
						node.current++;
						s.push(node);
					}
				}
			} else {
				visit[ node.current ] = 0;
				result.pop_back();
				node.current++;
				node.processed = false;
				s.push(node);
			}
		}

		result.clear();

		return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<pair<string, string>> tickets;
	vector<string> result;
	int i;

	tickets.push_back(make_pair("JFK", "SFO"));
	tickets.push_back(make_pair("JFK", "ATL"));
	tickets.push_back(make_pair("SFO", "ATL"));
	tickets.push_back(make_pair("ATL", "JFK"));
	tickets.push_back(make_pair("ATL", "SFO"));

	result = s.findItinerary(tickets);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
