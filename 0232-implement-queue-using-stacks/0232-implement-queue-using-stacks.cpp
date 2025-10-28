//Time Complexity: O(n)
//Space Complexity: O(n)
class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int popEle = -1;
        if(!s2.empty()) {
            popEle = s2.top();
        }
        else{
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            popEle = s2.top();
        }
        s2.pop();
        return popEle;
    }
    
    int peek() {
        int frontEle = -1;
        if(!s2.empty()){
            frontEle = s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            frontEle = s2.top();
        }
        return frontEle;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */