// https://leetcode.com/problems/reconstruct-itinerary/
// Time Limit Exceeded

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>

using namespace std;

class Solution {
private:
	struct Node {
		int current;
		int state;
	};
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
		stack<Node> s;
		Node node;
		vector<int> visit;
        vector<string> result;
		string bests, ings, from;
		bool flag;
		int i;

		ings = "JFK";

		visit.assign(tickets.size(), 0);
		node.current = 0;
		node.state = 0;
		s.push(node);

		while (!s.empty()) {
			node = s.top();
			s.pop();

			if (node.current >= tickets.size()) continue;

			if (node.state == 0) {
				if (visit[ node.current ] == 1) {
					node.current++;
					s.push(node);
				} else {
					from = ings.substr(ings.size() - 3, 3);
					if (bests.size() > 0 && bests < ings) {
						node.current++;
						s.push(node);
						continue;
					}
					if (tickets[ node.current ].first == from) {
						visit[ node.current ] = 1;
						ings += tickets[ node.current ].second;
						if (ings.size() / 3 > tickets.size()) {
							if (bests.size() == 0 || bests > ings) {
								bests = ings;
							}
						}
						node.state++;
						s.push(node);

						node.current = 0;
						node.state = 0;
						s.push(node);
					} else {
						node.current++;
						s.push(node);
					}
				}
			} else {
				visit[ node.current ] = 0;
				ings = ings.substr(0, ings.size() - 3);
				node.current++;
				node.state = 0;
				s.push(node);
			}
		}

		for (i = 0; i < bests.size(); i += 3) {
			result.push_back(bests.substr(i, 3));
		}

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
