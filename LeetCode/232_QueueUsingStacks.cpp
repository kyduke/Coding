// https://leetcode.com/problems/implement-queue-using-stacks/

#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
	stack<int> front;
	stack<int> back;
	int lastCommand;
	void swapStacks() {
		if (front.empty()) {
			while (!back.empty()) {
				front.push(back.top());
				back.pop();
			}
		} else {
			while (!front.empty()) {
				back.push(front.top());
				front.pop();
			}
		}
	}
public:
	Queue() : lastCommand(-1) {}
    // Push element x to the back of queue.
    void push(int x) {
		if (lastCommand != 1) {
			swapStacks();
			lastCommand = 1;
		}

		if (!front.empty()) {
			front.push(x);
		} else {
			back.push(x);
		}
    }

    // Removes the element from in front of queue.
    void pop(void) {
		if (lastCommand != 2) {
			swapStacks();
			lastCommand = 2;
		}

		if (!front.empty()) {
			front.pop();
		} else {
			back.pop();
		}
    }

    // Get the front element.
    int peek(void) {
		if (lastCommand != 2) {
			swapStacks();
			lastCommand = 2;
		}

		if (!front.empty()) {
			return front.top();
		} else {
			return back.top();
		}
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return front.empty() && back.empty();
    }
};


int main(int argc, char* argv[]) {
	Queue q;

	cout << q.empty() << ": true \n";
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.empty() << ": false \n";
	cout << q.peek() << ": 1 \n";
	q.pop();
	cout << q.peek() << ": 2 \n";
	q.pop();
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	cout << q.peek() << ": 3 \n";
	q.pop();
	q.push(8);
	q.push(9);
	q.push(10);

	while (!q.empty()) {
		cout << q.peek() << "\n";
		q.pop();
	}
	
	return 0;
}
