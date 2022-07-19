class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        long total=0;
        int ans=0;
        while(r<n){
            total+=nums[r];
            long sum = nums[r]*(long)(r-l+1);
            while(sum>(total+k)){
                total-=nums[l];
                l++;
                sum = nums[r]*(long)(r-l+1);
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};