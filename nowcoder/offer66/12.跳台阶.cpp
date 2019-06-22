
class Solution {
public:
    int jumpFloor(int number) {
        if(number<1) return 0;
        int a=1,b=2;
        while(--number){
            b=a+b;
            a=b-a;
        }
        return a;
    }
};
