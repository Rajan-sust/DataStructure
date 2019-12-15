#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q, temp;
    
    MyStack() {
            
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(int(q.size()) > 1){
            temp.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        swap(q,temp);
        return ans;
        
    }
    
    /** Get the top element. */
    int top() {
        
        while(int(q.size()) > 1){
            temp.push(q.front());
            q.pop();
        }
        int ans = q.front();
        temp.push(ans);
        q.pop();
        swap(q,temp);
        return ans;
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q.empty());
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
