// https://www.hackerrank.com/challenges/absolute-permutation/submissions/code/29435508

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 100001;

int arr[SIZE] = {0, };
int visit[SIZE] = {0, };

void solve(int n, int k) {
    int i;
    
    memset(arr, 0, sizeof(int) * (n + 1));
    memset(visit, 0, sizeof(int) * (n + 1));
    
    for (i = 1; i <= n; i++) {
        if (i - k > 0 && visit[i - k] == 0) {
            visit[i - k] = 1;
            arr[i] = i - k;
        } else if (i + k <= n && visit[i + k] == 0) {
            visit[i + k] = 1;
            arr[i] = i + k;
        } else {
            cout << "-1\n";
            return;
        }
    }
    
    for (i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int t, n, k;
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        
        solve(n, k);
    }
    
    return 0;
}
