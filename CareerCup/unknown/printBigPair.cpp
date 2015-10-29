#include <iostream>
#include <vector>

using namespace std;

void printBigPair(vector<int>& arr, int N) {
    unsigned int i, j;

    for (i = 0; i < arr.size(); i++) {
        for (j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] > N) cout << "(" << arr[i] << ", " << arr[j] << ") ";
        }
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    int data[] = {3, 7, 2, 5, 6, 4};
    vector<int> arr(data, data + 6);

    printBigPair(arr, 9);

    return 0;
}
