class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l=0,r=n-1;
        
        while(l<=r){
            
            int mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            
            //Left Sorted Part
            if(nums[l]<=nums[mid]){
                
                if(target<nums[l] or target>nums[mid]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
                
            }else{
                
                if(target>nums[r] or target<nums[mid]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        
        return -1;
    }
};