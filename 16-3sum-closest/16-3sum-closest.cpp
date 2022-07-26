class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int result = nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int start = i+1;
            int end  = n-1;
            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum>target){
                    end--;
                }else{
                    start++;
                }
                if(abs(sum-target)<abs(result-target)){
                    result=sum;
                }
            }
        }
        return result;
    }
};