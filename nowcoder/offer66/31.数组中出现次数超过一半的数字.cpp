
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len<=0) return 0;
        if(len==1) return numbers[0];
        int value,count;
        value=numbers[0];
        count=1;
        for(int i=0; i<len; i++){
            int num = numbers[i];
            if(count==0){
                value = num;
                count = 1;
            }else{
                if(value==num){
                    count++;
                }else{
                    count--;
                }
            }
        }
        count=0;
        for(int i=0 ; i<len; i++){
            if(numbers[i]==value){
                count++;
            }
        }
        return count>len/2?value:0;        
    }
};
