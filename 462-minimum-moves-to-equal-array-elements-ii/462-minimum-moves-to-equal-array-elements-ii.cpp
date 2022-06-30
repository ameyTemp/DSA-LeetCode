class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans=0;
        // cout<<sum<<endl;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            ans+=abs(nums[i]-nums[n-i-1]);
        }
        return ans;
    }
};