class MyQueue {
private:
    stack<int> s;  
    stack<int> ts; 

public:
    MyQueue() {
    }
    
    void push(int x) {
        while (!s.empty()) {
            ts.push(s.top()); 
            s.pop();       
        }
        s.push(x);
        
        
        while (!ts.empty()) {
            s.push(ts.top());
            ts.pop();
        }
    }
    
    int pop() {
        int topElement = s.top();
        s.pop();
        return topElement;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};