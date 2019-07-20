
class Solution {
    stack<int> s1,s2;
public:
    void push(int value) {
        s1.push(value);
        if(s2.empty())
            s2.push(value);
        else if(value<s2.top())
            s2.push(value);
    }
    void pop() {
        if(s2.top()==s1.top())
            s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
