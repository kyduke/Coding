class NumArray {
private:
    vector<long long> sums;
public:
    NumArray(vector<int> &nums) {
        int i;
        
        sums.clear();
        sums.push_back(0);
        for (i = 0; i < nums.size(); i++) {
            sums.push_back(sums[i] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};
