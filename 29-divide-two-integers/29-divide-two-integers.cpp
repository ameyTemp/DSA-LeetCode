class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==-1)
            return INT_MAX;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long ans = 0;
        int sign;
        if((dividend>0 and divisor>0) or (dividend<0 and divisor<0))
            sign=1;
        else
            sign=-1;
        while(dvd>=dvs){
            long temp = dvs;
            int m = 1;
            while(temp<<1<=dvd){
                temp=temp<<1;
                m=m<<1;
            }
            dvd-=temp;
            ans+=m;
        }
        return ans*sign;
    }
};