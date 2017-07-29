class MinStack {
#define MP(a,b) make_pair((a),(b))
    stack<pair<int,int>> data;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (data.empty()) data.push(MP(x,x));
        else data.push(MP(x,min(x,data.top().second)));
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return data.top().first;
    }
    
    int getMin() {
        return data.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */