class MyQueue {
    stack<int> tail;
    stack<int> head;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        tail.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!head.empty()){
            int x = head.top();
            head.pop();
            return x;
        }else{
            while(!tail.empty()){
                head.push(tail.top());
                tail.pop();
            }
            int x = head.top();
            head.pop();
            return x;
        }
    }
    
    /** Get the front element. */
    int peek() {
       if(!head.empty()){
            int x = head.top();
            return x;
        }else{
            while(!tail.empty()){
                head.push(tail.top());
                tail.pop();
            }
            int x = head.top();
            return x;
        } 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return head.empty() && tail.empty();
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