// https://codeforces.com/contest/1062/problem/B

#include <iostream>
#include <map>
#include <set>

using namespace std;

const int SIZE = 1000001;

set<int> primes;
int arr[SIZE] = {0, };

void findPrimes() {
	int i, j;
	
	for (i = 2; i < SIZE; i++) {
		if (arr[i] == 0) {
			primes.insert(i);
		}
		for (j = i; j < SIZE; j += i) {
			arr[j] = 1;
		}
	}
}

bool isPrime(int n) {
	return n == 1 || primes.find(n) != primes.end();
}

int main() {
	set<int>::iterator it;
	int n, ans, cnt, temp;
	bool flag;
	
	findPrimes();
	
	scanf("%d", &n);
	
	ans = 1;
	cnt = 0;
	if (isPrime(n) == true) {
		ans = n;
		cnt = 0;
	} else {
		flag = true;
		for (it = primes.begin(); it != primes.end(); it++) {
			if (n % *it == 0) {
				ans *= *it;
				temp = 0;
				while (n % *it == 0) {
					n /= *it;
					temp++;
				}
				if (cnt != 0 && cnt != temp) {
					flag = false;
				}
				cnt = max(cnt, temp);
			}
		}
		
		n = 0;
		temp = 1;
		while (temp < cnt) {
			n++;
			temp *= 2;
		}
		
		if (flag != true || temp != cnt) {
			n++;
		}
		cnt = n;
	}
	
	printf("%d %d\n", ans, cnt);
	
	return 0;
}

/*
20
=====
10 2

5184
=====
6 4
*/
