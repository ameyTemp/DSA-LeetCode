class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> arr;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(arr[target-nums[i]]!=0 and arr[target-nums[i]]!=i){
                return {i,arr[target-nums[i]]};
            }
        }
        return {};
    }
    
};