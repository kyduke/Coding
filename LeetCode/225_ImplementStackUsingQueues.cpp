// https://leetcode.com/problems/implement-stack-using-queues/

class Stack {
private:
    queue<int> in, out;
public:
    // Push element x onto stack.
    void push(int x) {
        in.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (in.size() > 1) {
            out.push(in.front());
            in.pop();
        }
        in.pop();
        while (!out.empty()) {
            in.push(out.front());
            out.pop();
        }
    }

    // Get the top element.
    int top() {
        int ret;
        
        while (in.size() > 1) {
            out.push(in.front());
            in.pop();
        }
        if (in.size() == 1) {
            ret = in.front();
            out.push(in.front());
            in.pop();
        }
        while (!out.empty()) {
            in.push(out.front());
            out.pop();
        }
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return in.empty();
    }
};
