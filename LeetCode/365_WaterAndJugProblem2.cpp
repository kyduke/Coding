// https://leetcode.com/problems/water-and-jug-problem/

class Solution {
private:
    int gcd(int a, int b) {
        int c;
        while (a != 0) {
            c = a;
            a = b % a;
            b = c;
        }
        return b;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y == z || ((x + y > z) && (z % gcd(x, y) == 0))) return true;
        return false;
    }
};
