#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int>& arr, int N) {
    int i;

    i = N;
    while (i--) {
        N ^= i ^ arr[i];
    }

    return N;
}

int main(int argc, char* argv[]) {
    int data[] = {0, 1, 2, 3, 4, 9, 5, 7, 6};
    vector<int> arr(data, data + 9);

    cout << findMissingNumber(arr, 9) << "\n";

    return 0;
}
