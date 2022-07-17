class Solution {
public:
    int gcd(int a,int b){
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int n = nums.size();
        int m = numsDivide.size();
        int g=numsDivide[0];
        for(int i=0;i<m;i++){
            g = gcd(numsDivide[i],g);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n and nums[i]<=g;i++){
            if(g%nums[i]==0)
                return i;
        }
        return -1;
    }
};