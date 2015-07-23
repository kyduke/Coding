// http://codeforces.com/problemset/problem/559/B

#include <iostream>
#include <string>

using namespace std;

int count1[26];
int count2[26];

bool isquivalent(string str1, string str2) {
    int i;
    if (str1.size() != str2.size()) return false;
    if (str1.compare(str2) == 0) return true;

    if (str1.size() % 2 == 1) return false;

    for (i = 0; i < 26; i++) {
        count1[i] = 0;
        count2[i] = 0;
    }

    for (i = 0; i < str1.size(); i++) {
        count1[str1[i] - 'a']++;
        count2[str2[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) return false;
    }

    i = str1.size() / 2;
    if (isquivalent(str1.substr(0, i), str2.substr(0, i)) && isquivalent(str1.substr(i), str2.substr(i))) return true;
    if (isquivalent(str1.substr(0, i), str2.substr(i)) && isquivalent(str1.substr(i), str2.substr(0, i))) return true;

    return false;
}

int main(int argc, char* argv[]) {
    string str1, str2;

    cin >> str1 >> str2;

    if (isquivalent(str1, str2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

/*
aaba
abaa
=====
YES

aabb
abab
=====
NO
*/
