class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int minele = INT_MIN;;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                count++;
                if(i-2<0 or nums[i-2]<=nums[i])
                    nums[i-1]=nums[i];
                else
                    nums[i]=nums[i-1];
            }
        }
        if(count<=1)
            return true;
        else
            return false;
    }
};