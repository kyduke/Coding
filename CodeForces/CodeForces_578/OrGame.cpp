// http://codeforces.com/problemset/problem/578/B
// http://codeforces.com/blog/entry/20368

#include<iostream>
#include<algorithm>

using namespace std;

const int SIZE = 2e5+2;

long long a[SIZE], prefix[SIZE], suffix[SIZE];

int main(){
    int n, k, x, i;
	long long mul, ans;

	cin >> n >> k >> x;

    mul = 1;
    while(k--) mul *= x;

    for(i = 1; i <= n; i++) cin >> a[i];

    for(i = 1; i <= n; i++) prefix[i] = prefix[i - 1] | a[i];
        
    for(i = n; i > 0; i--) suffix[i] = suffix[i + 1] | a[i];
        
    ans = 0;
    for(i= 1; i <= n; i++) ans = max(ans, prefix[i - 1] | (a[i] * mul) | suffix[i + 1]);
        
    cout << ans << "\n";
}

/*
3 1 2
1 1 1
=====
3

4 2 3
1 2 4 8
=====
79
*/
