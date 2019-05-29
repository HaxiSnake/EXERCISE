
class Solution {
public:
    int Add(int num1, int num2)
    {   
        int sum=0;
        int carry=0;
         
        while(num2!=0){
            sum=(num1^num2);
            carry=(num1&num2)<<1;
            num1=sum;
            num2=carry;
        }
        return num1;
    }
};
