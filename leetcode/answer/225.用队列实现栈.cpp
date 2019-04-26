class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        temp.push(x);
        while(que.size()){
            temp.push(que.front());
            que.pop();
        }
        que.swap(temp);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int rst = que.front();
        que.pop();
        return rst;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

private:
    queue<int> que,temp;
};