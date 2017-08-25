// https://www.welcomekakao.com/tryouts/1467/challenge_algorithm_codes/800

#include<vector>

using namespace std;

bool solution(vector<int> arr)
{
    int i, n;
    
    n = 0;
    for (i = 0; i < arr.size(); i++) {
        n ^= (i + 1);
        n ^= arr[i];
    }
    
	return n == 0;
}

/*
길이가 n인 배열에 1부터 n까지 숫자가 중복 없이 한 번씩 들어 있는지를 확인하려고 합니다.
1부터 n까지 숫자가 중복 없이 한 번씩 들어 있는 경우 true를, 아닌 경우 false를 반환하도록 함수 solution을 완성해주세요.

제한사항
배열의 길이는 10만 이하입니다.
배열의 원소는 10만 이하의 자연수입니다.
입출력 예
arr	result
[4, 1, 3, 2]	true
[4, 1, 3]	false
입출력 예 설명
입출력 예 #1
입력이 [4, 1, 3, 2]가 주어진 경우, 1부터 4까지 숫자가 모두 들어 있으므로 true를 반환하면 됩니다.

입출력 예 #2
[4, 1, 3]이 주어진 경우, 2가 없으므로 false를 반환하면 됩니다.
*/
