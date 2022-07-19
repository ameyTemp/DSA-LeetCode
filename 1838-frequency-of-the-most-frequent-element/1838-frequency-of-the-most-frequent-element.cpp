class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        long long total=0;
        int ans=0;
        while(r<n){
            total+=nums[r];
            
            while((long)nums[r]*(r-l+1)>(total+k)){
                total-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};