// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    vector<int> dummy;
    vector<int>& nums = dummy;
    int idx;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    this->nums = nums;
	    idx = 0;
	}

	int peek() {
        return nums[idx];
	}

	int next() {
	    int ret = peek();
	    idx++;
	    return ret;
	}

	bool hasNext() const {
	    return (idx < nums.size()) ? true : false;
	}
};
