// https://algospot.com/judge/problem/read/JAEHASAFE

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> KMPIndex(string& str) {
	vector<int> idx;
	int i, pos;

	idx.assign(str.size() + 1, -1);
	
	for (i = 1; i <= str.size(); i++) {
		pos = idx[i - 1];
		while (pos != -1 && str[pos] != str[i - 1]) {
			pos = idx[pos];
		}
		idx[i] = pos + 1;
	}

	return idx;
}

int KMPMatch(string& str, string& key, vector<int>& idx) {
	int strPos, keyPos;

	strPos = 0;
	keyPos = 0;
	while (strPos < str.size()) {
		while (keyPos != -1 && (keyPos == key.size() || key[keyPos] != str[strPos])) {
			keyPos = idx[keyPos];
		}
		keyPos++;
		strPos++;
		if (keyPos == key.size()) return strPos - key.size();
	}

	return -1;
}

int solve(vector<string>& arr) {
	vector<int> idx;
	string str;
	int i, ret, keyIndex;

	keyIndex = -1;
	ret = 0;
	for (i = 1; i < arr.size(); i++) {
		if (i % 2 == 0) {
			if (keyIndex != i) {
				keyIndex = i;
				idx = KMPIndex(arr[i]);
			}
			str = arr[i - 1] + arr[i - 1];
			ret += KMPMatch(str, arr[i], idx);
		} else {
			if (keyIndex != i - 1) {
				keyIndex = i - 1;
				idx = KMPIndex(arr[i - 1]);
			}
			str = arr[i] + arr[i];
			ret += KMPMatch(str, arr[i - 1], idx);
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int t, n;
	vector<string> arr;
	string str;

	cin >> t;
	while (t--) {
		cin >> n;
		arr.clear();
		n++;
		while (n--) {
			cin >> str;
			arr.push_back(str);
		}
		cout << solve(arr) << "\n";
	}
}

/*
2
3
abbab
babab
ababb
bbaba
2
RMDCMRCD
MRCDRMDC
DCMRCDRM
=====
6
10
*/
