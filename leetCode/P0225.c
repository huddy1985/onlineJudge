class Stack {
private:
    queue<int> que1,que2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(que2.empty())
            que1.push(x);
        else
            que2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(que2.empty()){
            int len = que1.size()-1;
            while(len--){
                que2.push(que1.front());
                que1.pop();
            }
            que1.pop();
        }else{
            int len = que2.size()-1;
            while(len--){
                que1.push(que2.front());
                que2.pop();
            }
            que2.pop();
        }
    }

    // Get the top element.
    int top() {
        if(que1.empty())
            return que2.back();
        return que1.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que1.empty() && que2.empty();
    }
};