class MinStack {
    vector<pair<int, int>> st;
    int idx;

public:
    MinStack() {
        st = vector<pair<int, int>>(3e4 + 1);
        idx = -1;
    }

    void push(int val) {
        idx++;
        st[idx].first = val;
        if (idx == 0) {
            st[idx].second = val;
        } else {
            st[idx].second = min(val, st[idx - 1].second);
        }
    }

    void pop() {
        if (idx == -1)
            return;
        idx--;
    }

    int top() {
        if (idx == -1)
            return -1;
        return st[idx].first;
    }

    int getMin() {
        if (idx == -1)
            return -1;
        return st[idx].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */