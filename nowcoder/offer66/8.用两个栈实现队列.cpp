
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        if(!stack2.empty()){
            int res=stack2.top();
            stack2.pop();
            return res;
        }else{
            if(!stack1.empty()){
                while(!stack1.empty()){
                    int res=stack1.top();
                    stack2.push(res);
                    stack1.pop();
                }
                int res=stack2.top();
                stack2.pop();
                return res;
            }else{
                return -1;
            }
        }
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};
