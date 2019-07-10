// https://codeforces.com/contest/1080/problem/A


By kyduke, contest: Codeforces Round #524 (Div. 2), problem: (A) Petya and Origami, Accepted, #
 #include <iostream>
 
using namespace std;
 
int main() {
	int ans, n, k;
	
	scanf("%d %d", &n, &k);
	
	ans = (n * 2) / k;
	if ((n * 2) % k != 0) ans++;
	ans += (n * 5) / k;
	if ((n * 5) % k != 0) ans++;
	ans += (n * 8) / k;
	if ((n * 8) % k != 0) ans++;
	
	printf("%d\n", ans);
	
	return 0;
}

/*
3 5
=====
10

15 6
=====
38
*/
