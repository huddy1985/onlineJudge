class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
    int min;
public:
    MinStack():min(2147483647){
    }
    void push(int x) {
        stk.push(x);
        if(x < min){
            min_stk.push(x);
            min = x;
        }
        else
            min_stk.push(min);
    }

    void pop() {
        stk.pop();
        min_stk.pop();
        if(min_stk.empty())
            min = 2147483647;
        else
            min = min_stk.top();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};