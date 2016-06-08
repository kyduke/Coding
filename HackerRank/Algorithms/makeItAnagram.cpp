// https://www.hackerrank.com/challenges/make-it-anagram

#include <iostream>
#include <string>

using namespace std;

int solve(string& a, string& b) {
    int as[26] = {0, };
    int bs[26] = {0, };
    int answer, i;
    
    answer = 0;
    for (i = 0; i < a.size(); i++) as[ a[i] - 'a' ]++;
    for (i = 0; i < b.size(); i++) bs[ b[i] - 'a' ]++;
    
    for (i = 0; i < 26; i++) answer += max(as[i] - bs[i], bs[i] - as[i]);
    
    return answer;
}

int main() {
    string a, b;
    
    cin >> a >> b;
    
    cout << solve(a, b) << "\n";
    
    return 0;
}

/*
cde
abc
=====
4
*/
