//
//  main.cpp
//  AlgoSpot_KTHDICTNUM
//
//  Created by Youngduke Koh on 8/18/15.
//  Copyright (c) 2015 Youngduke Koh. All rights reserved.
//

/*
0 부터 N까지 정열에서 k번째 숫자 찾기 완성
아래 문제에서는 a가 0인 경우에만 답을 찾음
*/

// https://www.algospot.com/judge/problem/read/KTHDICTNUM

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

//brute force
UINT64 bruteforce(UINT64 a, UINT64 b, UINT64 k) {
    UINT64 i, n, c;
    
    if (k == 0 && a == 0) return 0;
    
    c = 0;
    i = 0;
    if (a == 0) {
        c++;
        i++;
    }
    while (i <= b) {
        if (i % 10 != 0) {
            n = i;
            while (n < a) n *= 10;
            while (n <= b) {
                if (c == k) return n;
                n *= 10;
                c++;
            }
        }
        i++;
    }
    
    return 0;
}

int getLength(UINT64 n) {
	int length;

	length = 0;
	while(n) {
		length++;
		n /= 10;
	}

	return length;
}

UINT64 getLimit(int length) {
	UINT64 limit;

	limit = 1;
	while (length) {
		limit *= 10;
		length--;
	}

	return limit;
}

UINT64 getMaxCount(int length) {
	UINT64 count;

	if (length == 0) return 1;
	if (length == 1) return 9;

	count = 81;

	length -= 2;
	while (length) {
		count *= 10;
		length--;
	}

	return count;
}

UINT64 getCountWithLengthWithoutZero(UINT64 n, int length) {
	UINT64 limit, maxCount, count;
	int nLength;

	nLength = getLength(n);
	if (nLength < length) return 0;
	if (length == 0) return 1;

	count = 0;

	limit = getLimit(length);
	maxCount = getMaxCount(length);

	if (n >= limit) {
		count = maxCount;
	} else {
		count = n - (limit / 10);
		count = count - count / 10;
		if (length == 1) count++;
	}

	return count;
}

UINT64 getCountWithLengthWithZero(UINT64 n, int length) {
	UINT64 limit, maxCount, count;
	int nLength;

	nLength = getLength(n);
	if (nLength < length) return 0;
	if (length == 0) return 1;

	count = 0;

	limit = getLimit(length);
	maxCount = getMaxCount(length);

	if (n >= limit) {
		count = maxCount * (nLength - length);
		count += getCountWithLengthWithoutZero(n / getLimit(nLength - length), length);
	} else {
		count = n - (limit / 10);
		count = count - count / 10;
		if (length == 1) count++;
	}

	return count;
}

UINT64 increaseWithoutZero(UINT64 n, UINT64 m) {
	UINT64 a, b, r;

	a = 0;
	while (true) {
		r = n + m + a;
		b = (r / 10) - (n / 10);
		if (a == b) break;
		a = b;
	}

	return r;
}

UINT64 solve(UINT64 a, UINT64 b, UINT64 k) {
	int nLength, length;
	UINT64 count, n;
	UINT64 x;
	int y;
	UINT64 result;

	if (k == 0 && a == 0) return 0;

	n = b;
	k += a;

	result = 0;

	nLength = getLength(n);
	length = 0;
	
	while(true) {
		count = getCountWithLengthWithZero(n, length);
		if (count <= k) {
			k -= count;
		} else {
			count = getCountWithLengthWithoutZero(n / getLimit(nLength), length);

			result = 1;
			if (length > 1) result += getLimit(length - 1);
			if (result < a) result = a;

			x = k / (nLength + 1);
			y = k % (nLength + 1);
			
			if (x >= count) {
				result = increaseWithoutZero(result, count);
				k -= count * (nLength + 1);
				y = 0;
				if (nLength > 0) {
					x = k / nLength;
					y = k % nLength;

					result = increaseWithoutZero(result, x);
				}
				nLength--;
			} else {
				result = increaseWithoutZero(result, x);
			}

			result *= getLimit(y);
			
			break;
		}
		nLength--;
		length++;
	}

	if (result < a) result = a;

	return result;
}

int main(int argc, char* argv[]) {
	int T;
	UINT64 a, b, k;
	
	cin >> T;
	while (T--) {
		cin >> a >> b >> k;
		cout << bruteforce(a, b, k) << "\n";
		cout << solve(a, b, k) << "\n";
	}

	return 0;
}

/*
3
1 10 0
1 10 1
1 10 2
=====
1
10 
2
*/
