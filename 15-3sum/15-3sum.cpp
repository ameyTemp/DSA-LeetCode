class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int start = i+1;
            int end = n-1;
            while(start<end){
                int sum =nums[i] + nums[start] + nums[end];
                if(sum==0){
                    res.insert({nums[i],nums[start],nums[end]});
                    while(start<end && nums[start+1]==nums[start]){
                        start++;
                    }
                    // start=end;
                    // break;
                }
                if(sum>=0){
                    end--;
                }
                if(sum<0){
                    start++;
                }
                
            }
        }
        vector<vector<int>> ans;
        for(auto i:res)
            ans.push_back(i);
        
        return ans;
    }
};