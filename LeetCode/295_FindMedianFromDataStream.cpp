class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        int a, b;
        
        if (left.size() == 0) {
            left.push(num);
            return;
        }
        
        right.push(num);
        while (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
        while (left.top() > right.top()) {
            a = left.top();
            left.pop();
            b = right.top();
            right.pop();
            
            left.push(b);
            right.push(a);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        double m;
        
        if (left.size() > right.size()) {
            m = left.top();
        } else {
            m = left.top() + right.top();
            m /= 2.0;
        }
        
        return m;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
