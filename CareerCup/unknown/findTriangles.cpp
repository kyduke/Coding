// http://careercup.com/question?id=5745534851612672

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > findTriangles(vector<int> nums) {
    vector< vector<int> > triangles;
    vector<int> triangle;
    int i, j, k;

    for (i = 0; i < nums.size() - 2; i++) {
        for (j = i + 1; j < nums.size() - 1; j++) {
            for (k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] <= nums[k]) continue;
                if (nums[j] + nums[k] <= nums[i]) continue;
                if (nums[k] + nums[i] <= nums[j]) continue;
                triangle.clear();
                triangle.push_back(nums[i]);
                triangle.push_back(nums[j]);
                triangle.push_back(nums[k]);
                triangles.push_back(triangle);
            }
        }
    }

    return triangles;
}

void printTriangles(vector< vector<int> > triangles) {
    int i, j;

    for (i = 0; i < triangles.size(); i++) {
        for (j = 0; j < 3; j++) {
            cout << triangles[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    vector< vector<int> > triangles;
    vector<int> nums;
    int data[] = {10, 5, 3, 4, 7, 1};

    nums.assign(data, data + 6);
    triangles = findTriangles(nums);

    printTriangles(triangles);

    return 0;
}
