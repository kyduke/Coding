// http://careercup.com/question?id=5682825644736512

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
vector< pair<string, int> > substringCountKMP(string str, int k) {
    vector< pair<string, int> > ret;
    vector<int> fails(str.size() + 1, -1);
    vector<int> counts(str.size() + 1, 1);
    int i, pos;
 
    for (i = 1; i <= str.size(); i++) {
        pos = fails[i - 1];
        while (pos != -1 && str[pos] != str[i - 1]) {
            pos = fails[pos];
        }
        fails[i] = pos + 1;
    }

    for (i = fails.size() - 1; i > 0; i--) {
        if (fails[i] >= k) {
            counts[ fails[i] ] += counts[i];
            counts[i] = 0;
        }
    }

    for (i = k; i < counts.size(); i++) {
        if (counts[i] == 0) continue;
        ret.push_back(make_pair(str.substr(i - k, k), counts[i]));
    }
 
    for (i = 0; i < fails.size(); i++) {
        cout << fails[i] << " ";
    }
    cout << "\n";

    for (i = 0; i < fails.size(); i++) {
        cout << counts[i] << " ";
    }
    cout << "\n";

    return ret;
}

void printAnswer(vector< pair<string, int> > answer) {
    int i;

    for (i = 0; i < answer.size(); i++) {
        cout << answer[i].first << ": " << answer[i].second << "\n";
    }
}

int main(int argc, char* argv[]) {
    vector< pair<string, int> > answer;

    answer = substringCountKMP("ABCGRETCABCG", 3);
    printAnswer(answer);

    answer = substringCountKMP("ABCABCABCABC", 3);
    printAnswer(answer); 

    return 0;
}
