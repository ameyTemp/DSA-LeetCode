class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num){
            if(num%2==1)
                num-=1;
            else
                num=num/2;
            cout<<num<<" ";  
            count++;
        }
        return count;
    }
};