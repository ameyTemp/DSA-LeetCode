class Solution {
public:
    int sumofSquares(int n){
        int sum=0;
        while(n){
            int digit=n%10;
            digit = digit*digit;
            // cout<<digit;
            sum+=(digit);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n==1)
            return true;
        map<int,int> cycle;
        int temp=n;
        while(cycle[temp]!=1){
            cycle[temp]=1;
            // cout<<temp<<endl;
            temp = sumofSquares(temp); 
            if(temp==1)
                return true;
        }
        return false;
    }
};